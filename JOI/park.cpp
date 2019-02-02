#include"park.h"
#include<string.h>
#include<algorithm>
#include<assert.h>
using namespace std;
int h[1410],nex[3010],to[3010],M;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
int pl[1410],n;
bool fb[1410];
int cnt;
void ans(int a,int b){
	if(a>b)swap(a,b);
	assert(a<b);
	Answer(a,b);
	add(a,b);
	add(b,a);
	cnt++;
}
int ask(int a,int b){
	if(a>b)swap(a,b);
	assert(a<b&&pl[a]&&pl[b]);
	return Ask(a,b,pl);
}
bool us[1410];
int dfn[1410],id[1410],tm;
bool vis[1410];
void dfs(int x){
	dfn[x]=++tm;
	id[tm]=x;
	vis[x]=1;
	for(int i=h[x];i;i=nex[i]){
		if(!vis[to[i]])dfs(to[i]);
	}
}
int get(int x){
	int l,r,mid,i;
	memset(vis,0,sizeof(vis));
	tm=0;
	dfs(0);
	l=1;
	r=tm;
	while(l<r){
		mid=(l+r)>>1;
		for(i=0;i<n;i++)pl[i]=!us[i]||dfn[i]<=mid;
		if(ask(0,x))
			r=mid;
		else
			l=mid+1;
	}
	for(i=0;i<n;i++)fb[i]=us[i]&&dfn[i]>l;
	return id[l];
}
bool cn(int x,int y){
	assert(x!=y);
	for(int i=0;i<n;i++)pl[i]=i==x||i==y;
	return ask(x,y);
}
int getmid(int x,int y){
	int l,r,mid,i;
	l=0;
	r=n-1;
	while(l<r){
		mid=(l+r)>>1;
		for(i=0;i<n;i++)pl[i]=(i==x||i==y||i<=mid)&&!fb[i];
		if(ask(x,y))
			r=mid;
		else
			l=mid+1;
	}
	return l;
}
int sx[1510],sy[1510],tp;
void push(int x,int y){
	tp++;
	sx[tp]=x;
	sy[tp]=y;
}
bool del[1410];
int col[1410],C;
void dfs2(int x){
	col[x]=C;
	for(int i=h[x];i;i=nex[i]){
		if(!del[to[i]]&&col[to[i]]!=C)dfs2(to[i]);
	}
}
void dfs3(int x){
	dfn[x]=++tm;
	id[tm]=x;
	vis[x]=1;
	for(int i=h[x];i;i=nex[i]){
		if(!del[to[i]]&&!vis[to[i]])dfs3(to[i]);
	}
}
void getedge(int x,int y){
	int i,l,r,mid;
	if(x==-1){
		for(i=0;i<n;i++){
			if(col[i]==C){
				x=i;
				break;
			}
		}
		assert(~x);
		for(i=0;i<n;i++)pl[i]=i==y||col[i]==C;
		if(!ask(x,y))return;
		memset(vis,0,sizeof(vis));
		tm=0;
		dfs3(x);
		l=1;
		r=tm;
		while(l<r){
			mid=(l+r)>>1;
			for(i=0;i<n;i++)pl[i]=i==y||(vis[i]&&dfn[i]<=mid);
			if(ask(x,y))
				r=mid;
			else
				l=mid+1;
		}
		x=id[l];
	}
	push(x,y);
	del[x]=1;
	r=C;
	for(i=0;i<n;i++){
		if(col[i]==r&&!del[i]){
			C++;
			dfs2(i);
			getedge(-1,y);
		}
	}
}
void solve(int x,int y){
	if(!cn(x,y)){
		int z=getmid(x,y);
		solve(x,z);
		solve(z,y);
		return;
	}
	int i;
	tp=0;
	memset(del,0,sizeof(del));
	memset(col,0,sizeof(col));
	C=1;
	for(i=0;i<n;i++){
		if(us[i])col[i]=1;
	}
	getedge(x,y);
	while(tp){
		ans(sx[tp],sy[tp]);
		tp--;
	}
	us[y]=1;
}
void Detect(int T,int N){
	n=N;
	us[0]=1;
	for(int i=1;i<N;i++){
		if(!us[i])solve(get(i),i);
	}
}
