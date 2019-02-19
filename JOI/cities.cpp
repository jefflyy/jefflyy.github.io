#include<stdio.h>
void fmax(int&a,int b){
	if(a<b)a=b;
}
int h[200010],nex[400010],to[400010],M,n;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
int d[200010];
void dfs1(int fa,int x){
	d[x]=d[fa]+1;
	for(int i=h[x];i;i=nex[i]){
		if(to[i]!=fa)dfs1(x,to[i]);
	}
}
void getdia(int&x,int&y){
	int i;
	dfs1(0,1);
	x=0;
	for(i=1;i<=n;i++){
		if(d[i]>d[x])x=i;
	}
	dfs1(0,x);
	y=0;
	for(i=1;i<=n;i++){
		if(d[i]>d[y])y=i;
	}
}
int md[200010],dep[200010];
void dfs2(int fa,int x){
	int i,t=0;
	dep[x]=dep[fa]+1;
	for(i=h[x];i;i=nex[i]){
		if(to[i]!=fa){
			dfs2(x,to[i]);
			fmax(t,md[to[i]]);
		}
	}
	md[x]=t+1;
}
int cnt[200010],res;
void add(int x){
	res+=!cnt[x]++;
}
void del(int x){
	res-=!--cnt[x];
}
int c[200010];
int st[200010],tp;
void push(int x){
	st[++tp]=x;
	add(c[x]);
}
void pop(){
	del(c[st[tp--]]);
}
int ans[200010];
void dfs3(int fa,int x){
	int i,p,t;
	p=0;
	for(i=h[x];i;i=nex[i]){
		if(to[i]!=fa&&md[to[i]]>md[p])p=to[i];
	}
	if(!p)goto end;
	t=0;
	for(i=h[x];i;i=nex[i]){
		if(to[i]!=fa&&to[i]!=p)fmax(t,md[to[i]]);
	}
	#define gao(y,t) {\
		while(tp&&dep[st[tp]]>=dep[x]-t)pop();\
		push(x);\
		dfs3(x,y);\
	}
	gao(p,t)
	t=md[p];
	for(i=h[x];i;i=nex[i]){
		if(to[i]!=fa&&to[i]!=p)gao(to[i],t)
	}
	while(tp&&dep[st[tp]]>=dep[x]-t)pop();
	end:fmax(ans[x],res);
}
void work(int x){
	dfs2(0,x);
	dfs3(0,x);
}
int main(){
	int m,i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(i=1;i<=n;i++)scanf("%d",c+i);
	getdia(x,y);
	work(x);
	work(y);
	for(i=1;i<=n;i++)printf("%d\n",ans[i]);
}
