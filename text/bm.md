Berlekamp-Massey算法，简称BM，用于寻找数列的最短递推式

给定数列$a_{1\cdots n}$，目标是找到递推式$R=\{r_{1\cdots m}\}$，满足对$\forall m+1\leq k\leq n$有$\sum\limits_{j=1}^mr_ja_{k-j}=a_k$

-----

对一个递推式$R$，要记第一次失败的位置$f_R$，以及这个位置的偏差值$d_R=a_{f_R}-\sum\limits_{j=1}^mr_ja_{f_R-j}$

一开始令$R=\{\}$，遇到第一个$a_i\ne0$的位置就令$R=\{i\cdot0\}$

接下来如果$R$不满足$a_i$，那么在之前的所有除$R$外的递推式中找到$|R|-f_R$最小的$R'$，令$t=\frac{d_R}{d_{R'}}$，那么新的满足$a_i$的递推式就是$R+\{(i-f_{R'}-1)\cdot0,t,-tR'\}$，加号表示按位相加，容易验证这确实是递推式

找$R'$只需记录下来即可

-------

xsy上的模板题

```c++
int a[10010];
struct tr{
	int b[3010],k,f,d;
	int&operator[](int k){return b[k];}
}fr,se,tmp;
int get(int i){
	int j,s;
	s=0;
	for(j=1;j<=fr.k;j++)inc(s,mul(fr[j],a[i-j]));
	return s;
}
int main(){
	int n,i,j,d,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++){
		d=ad(a[i],mod-get(i));
		if(!d)continue;
		if(!fr.k){
			fr.k=i;
			se.f=i;
			se.d=d;
			continue;
		}
		t=mul(d,pow(se.d,mod-2));
		tmp=fr;
		tmp.k=max(fr.k,i-se.f+se.k);
		inc(tmp[i-se.f],t);
		for(j=1;j<=se.k;j++)inc(tmp[i-se.f+j],mod-mul(t,se[j]));
		fr.f=i;
		fr.d=d;
		if(fr.k-fr.f<se.k-se.f)se=fr;
		fr=tmp;
	}
	printf("%d\n",fr.k);
	printf("%d",mod-1);
	for(i=1;i<=fr.k;i++)printf(" %d",fr[i]);
}
```