#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=998244353;
int ad(int a,int b){return(a+=b)>=mod?a-mod:a;}
struct mat{
	int a[4][4];
	void one(){
		memset(a,0,sizeof(a));
		for(int i=0;i<4;i++)a[i][i]=1;
	}
	bool any(){
		int i,j;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(a[i][j]!=(i==j))return 1;
			}
		}
		return 0;
	}
	int*operator[](int k){return a[k];}
	const int*operator[](int k)const{return a[k];}
}d[1000010],t;
mat operator*(const mat&a,const mat&b){
	mat c;
	int i,j,k;
	ll t;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			t=0;
			for(k=0;k<4;k++)t+=(ll)a[i][k]*b[k][j];
			c[i][j]=t%mod;
		}
	}
	return c;
}
struct vec{
	int a[4];
	int&operator[](int k){return a[k];}
	int operator[](int k)const{return a[k];}
}s[1000010],u;
vec operator+(const vec&a,const vec&b){
	vec c;
	for(int i=0;i<4;i++)c[i]=ad(a[i],b[i]);
	return c;
}
vec operator*(const vec&a,const mat&b){
	int i,j;
	vec c;
	ll t;
	for(i=0;i<4;i++){
		t=0;
		for(j=0;j<4;j++)t+=(ll)a[j]*b[j][i];
		c[i]=t%mod;
	}
	return c;
}
int a[250010],b[250010],c[250010];
void pushup(int x){
	s[x]=s[x<<1]+s[x<<1|1];
}
void build(int l,int r,int x){
	d[x].one();
	if(l==r){
		s[x][0]=a[l];
		s[x][1]=b[l];
		s[x][2]=c[l];
		s[x][3]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	pushup(x);
}
void ad(int x,const mat&v){
	s[x]=s[x]*v;
	d[x]=d[x]*v;
}
void pushdown(int x){
	if(d[x].any()){
		ad(x<<1,d[x]);
		ad(x<<1|1,d[x]);
		d[x].one();
	}
}
void modify(int L,int R,const mat&v,int l,int r,int x){
	if(L<=l&&r<=R)return ad(x,v);
	pushdown(x);
	int mid=(l+r)>>1;
	if(L<=mid)modify(L,R,v,l,mid,x<<1);
	if(mid<R)modify(L,R,v,mid+1,r,x<<1|1);
	pushup(x);
}
vec query(int L,int R,int l,int r,int x){
	if(L<=l&&r<=R)return s[x];
	pushdown(x);
	int mid=(l+r)>>1;
	if(R<=mid)return query(L,R,l,mid,x<<1);
	if(mid<L)return query(L,R,mid+1,r,x<<1|1);
	return query(L,R,l,mid,x<<1)+query(L,R,mid+1,r,x<<1|1);
}
int main(){
	int n,m,i,l,r,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d%d",a+i,b+i,c+i);
	build(1,n,1);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&i,&l,&r);
		if(4<=i&&i<=6)scanf("%d",&v);
		t.one();
		if(i==1)t[1][0]=1;
		if(i==2)t[2][1]=1;
		if(i==3)t[0][2]=1;
		if(i==4)t[3][0]=v;
		if(i==5)t[1][1]=v;
		if(i==6){
			t[2][2]=0;
			t[3][2]=v;
		}
		if(i==7){
			u=query(l,r,1,n,1);
			printf("%d %d %d\n",u[0],u[1],u[2]);
		}else
			modify(l,r,t,1,n,1);
	}
}
