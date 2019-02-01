#include<stdio.h>
#include<algorithm>
using namespace std;
void fmax(int&a,int b){
	if(a<b)a=b;
}
int h[10010],nex[40010],to[40010],M;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
int fa[10010],dfn[10010],low[10010],dep[10010];
void dfs(int x){
	dfn[x]=low[x]=++M;
	dep[x]=dep[fa[x]]+1;
	for(int i=h[x];i;i=nex[i]){
		if(!dfn[to[i]]){
			fa[to[i]]=x;
			dfs(to[i]);
			low[x]=min(low[x],low[to[i]]);
		}else if(to[i]!=fa[x])
			low[x]=min(low[x],dfn[to[i]]);
	}
}
int f[10010],g[10010],p[10010];
int ring(int x,int y,int&sg){
	int i,s,t;
	M=0;
	for(i=x;i!=y;i=fa[i])p[++M]=i;
	p[++M]=y;
	s=M;
	t=0;
	for(i=1;i<M;i++){
		s+=g[p[i]];
		fmax(t,M-i+f[p[i]]-s);
	}
	s=M;
	for(i=M-1;i>0;i--){
		s+=g[p[i]];
		fmax(t,i+f[p[i]]-s);
	}
	sg+=s;
	return t;
}
void dfs2(int x){
	int i;
	for(i=h[x];i;i=nex[i]){
		if(dep[to[i]]==dep[x]+1){
			dfs2(to[i]);
			if(low[to[i]]>dfn[x])fmax(f[x],f[to[i]]+1);
		}
	}
	for(i=h[x];i;i=nex[i]){
		if(dep[to[i]]>dep[x]+1)fmax(f[x],ring(to[i],x,g[x]));
	}
	f[x]+=g[x];
}
int main(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	M=0;
	dfs(1);
	dfs2(1);
	printf("%d",f[1]);
}
