#include<stdio.h>
#include<vector>
using namespace std;
typedef long long ll;
char c[3000000];
int ns;
#define NUM(x) ('0'<=x&&x<='9')
int rd(){
	while(!NUM(c[ns]))ns++;
	int x=0;
	while(NUM(c[ns]))x=x*10+c[ns++]-'0';
	return x;
}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
struct pr{
	int v,c;
	pr(int v=0,int c=0):v(v),c(c){}
};
typedef vector<pr> vp;
vp operator+(vp a,vp b){
	pr t;
	int i,s;
	t=*a.rbegin();
	a.pop_back();
	s=t.v;
	for(i=0;i<(int)b.size();i++){
		s=gcd(s,b[i].v);
		if(s==t.v)
			t.c+=b[i].c;
		else{
			a.push_back(t);
			t=pr(s,b[i].c);
		}
	}
	a.push_back(t);
	return a;
}
struct dat{
	ll s;
	vp l,r;
	dat(){}
	dat(int v):s(v>1),l(1,pr(v,1)),r(1,pr(v,1)){}
}t[400010];
dat operator+(dat a,dat b){
	dat c;
	int i,j;
	ll s,t;
	j=0;
	s=t=0;
	for(i=(int)a.r.size()-1;i>=0;i--){
		while(j<(int)b.l.size()&&gcd(a.r[i].v,b.l[j].v)>1)t+=b.l[j++].c;
		s+=a.r[i].c*t;
	}
	c.s=a.s+b.s+s;
	c.l=a.l+b.l;
	c.r=b.r+a.r;
	return c;
}
int p[100010];
void pushup(int x){
	t[x]=t[x<<1]+t[x<<1|1];
}
void build(int l,int r,int x){
	if(l==r){
		t[x]=p[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,x<<1);
	build(mid+1,r,x<<1|1);
	pushup(x);
}
void modify(int p,int v,int l,int r,int x){
	if(l==r){
		t[x]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)
		modify(p,v,l,mid,x<<1);
	else
		modify(p,v,mid+1,r,x<<1|1);
	pushup(x);
}
dat query(int L,int R,int l,int r,int x){
	if(L<=l&&r<=R)return t[x];
	int mid=(l+r)>>1;
	if(R<=mid)return query(L,R,l,mid,x<<1);
	if(mid<L)return query(L,R,mid+1,r,x<<1|1);
	return query(L,R,l,mid,x<<1)+query(L,R,mid+1,r,x<<1|1);
}
int main(){
	fread(c,1,3000000,stdin);
	int n,m,i,x,y;
	n=rd();
	m=rd();
	for(i=1;i<=n;i++)p[i]=rd();
	build(1,n,1);
	while(m--){
		i=rd();
		x=rd();
		y=rd();
		if(i==1)
			modify(x,y,1,n,1);
		else
			printf("%I64d\n",query(x,y,1,n,1).s);
	}
}
