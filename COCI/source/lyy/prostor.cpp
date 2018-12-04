#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mx=1000;
struct rect{
	int a[3],b[3];
}p[3][100010];
int n[3];
int lowbit(int x){return x&-x;}
struct bit{
	int s[1010][1010];
	void clear(){
		memset(s,0,sizeof(s));
	}
	void modify(int x,int y,int v){
		int i;
		while(x<=mx){
			for(i=y;i<=mx;i+=lowbit(i))s[x][i]+=v;
			x+=lowbit(x);
		}
	}
	int query(int x,int y){
		int i,res=0;
		while(x){
			for(i=y;i;i-=lowbit(i))res+=s[x][i];
			x-=lowbit(x);
		}
		return res;
	}
}a,b;
int query(int xr,int yl,int yr){
	return a.query(xr,yr)-b.query(xr,yl-1);
}
int query(int xl,int xr,int yl,int yr){
	return query(xr,yl,yr)-query(xl-1,yl,yr);
}
void modify(int x,int yl,int yr,int v){
	a.modify(x,yl,v);
	b.modify(x,yr,v);
}
struct eve{
	int y,xl,xr,zl,zr,t;//t=1:add&query,-1:del
	eve(int y=0,int a=0,int b=0,int c=0,int d=0,int t=0):y(y),t(t){
		if(a>b)swap(a,b);
		if(c>d)swap(c,d);
		xl=a;
		xr=b;
		zl=c;
		zr=d;
	}
}q[200010];
bool operator<(eve a,eve b){
	return a.y==b.y?(a.t==b.t?a.xr-a.xl<b.xr-b.xl:a.t<b.t):a.y<b.y;
}
ll solve(int x,int y){
	int M,i,z;
	rect t;
	ll s;
	eve u;
	z=3-x-y;
	M=0;
	for(i=1;i<=n[x];i++){
		t=p[x][i];
		if(t.a[y]>t.b[y])swap(t.a[y],t.b[y]);
		q[++M]=eve(t.a[y],t.a[x],t.a[x],t.a[z],t.b[z],1);
		q[++M]=eve(t.b[y]+1,t.a[x],t.a[x],t.a[z],t.b[z],-1);
	}
	for(i=1;i<=n[y];i++){
		t=p[y][i];
		q[++M]=eve(t.a[y],t.a[x],t.b[x],t.a[z],t.b[z],1);
	}
	sort(q+1,q+M+1);
	s=0;
	a.clear();
	b.clear();
	for(i=1;i<=M;i++){
		u=q[i];
		if(u.t==1)s+=query(u.xl,u.xr,u.zl,u.zr);
		if(u.xl==u.xr)modify(u.xl,u.zl,u.zr,u.t);
	}
	return s;
}
int main(){
	int m,i;
	rect t;
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d%d%d%d",t.a,t.a+1,t.a+2,t.b,t.b+1,t.b+2);
		for(i=0;i<3;i++){
			if(t.a[i]==t.b[i])p[i][++n[i]]=t;
		}
	}
	printf("%I64d",solve(0,1)+solve(1,2)+solve(2,0));
}
