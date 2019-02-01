#include<stdio.h>
#include<algorithm>
using namespace std;
const int inf=2147483647;
template<class t>void fmax(t&a,t b){
	if(a<b)a=b;
}
int h[300010],to[600010],nex[600010],M;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
struct pr{
	int x,d;
	pr(int x=0,int d=0):x(x),d(d){}
}d1[300010],u1[300010];
pr operator+(pr a,int b){return pr(a.x,a.d+b);}
bool operator<(pr a,pr b){return a.d<b.d;}
struct tr{
	int x,y,d;
	tr(int x=0,int y=0,int d=0):x(x),y(y),d(d){}
	tr(pr a,int x):x(x),y(a.x),d(a.d){}
}d2[300010],u2[300010];
tr operator+(pr a,pr b){return tr(a.x,b.x,a.d+b.d);}
bool operator<(tr a,tr b){return a.d<b.d;}
int fa[300010],dep[300010];
void dfs1(int x){
	dep[x]=dep[fa[x]]+1;
	d1[x]=x;
	d2[x]=tr(x,x);
	for(int i=h[x];i;i=nex[i]){
		if(to[i]!=fa[x]){
			fa[to[i]]=x;
			dfs1(to[i]);
			fmax(d2[x],max(d1[x]+(d1[to[i]]+1),d2[to[i]]));
			fmax(d1[x],d1[to[i]]+1);
		}
	}
}
pr t1[300010];
tr t2[300010];
void dfs2(int x){
	int i;
	pr u;
	tr t;
	M=0;
	for(i=h[x];i;i=nex[i]){
		if(to[i]!=fa[x]){
			M++;
			t1[M]=d1[to[i]]+1;
			t2[M]=d2[to[i]];
		}
	}
	t1[M+1]=x;
	t2[M+1]=tr(x,x);
	for(i=M;i>0;i--){
		fmax(t2[i],max(t2[i+1],t1[i]+t1[i+1]));
		fmax(t1[i],t1[i+1]);
	}
	M=0;
	u=x;
	t=tr(x,x);
	for(i=h[x];i;i=nex[i]){
		if(to[i]!=fa[x]){
			M++;
			u1[to[i]]=max(max(u,t1[M+1]),u1[x])+1;
			u2[to[i]]=max(max(max(t,t2[M+1]),max(tr(u1[x],x),u+t1[M+1])),max(u2[x],max(u,t1[M+1])+u1[x]));
			fmax(t,max(u+(d1[to[i]]+1),d2[to[i]]));
			fmax(u,d1[to[i]]+1);
		}
	}
	for(i=h[x];i;i=nex[i]){
		if(to[i]!=fa[x])dfs2(to[i]);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=fa[x];
	while(x!=y){
		x=fa[x];
		y=fa[y];
	}
	return x;
}
int mid(tr t){
	int x,y,l;
	x=t.x;
	y=t.y;
	if(dep[x]<dep[y])swap(x,y);
	for(l=(dep[x]+dep[y]-dep[lca(x,y)]*2)/2;l--;x=fa[x]);
	return x;
}
int main(){
	int n,i,x,y,mn,p,t;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(1);
	u1[1]=1;
	u2[1]=tr(1,1);
	dfs2(1);
	mn=inf;
	p=0;
	for(i=2;i<=n;i++){
		t=max(max(d2[i].d,u2[i].d),(d2[i].d+1)/2+(u2[i].d+1)/2+1);
		if(t<mn){
			mn=t;
			p=i;
		}
	}
	printf("%d\n%d %d\n%d %d",mn,p,fa[p],mid(d2[p]),mid(u2[p]));
}
