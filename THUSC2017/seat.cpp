#include<stdio.h>
#include<string.h>
#include<queue>
#include<assert.h>
using namespace std;
const int inf=2147483647,maxn=18010,maxm=120010;
#define cos cos_
int h[maxn],nex[maxm],to[maxm],cap[maxm],cos[maxm],M=1,S,T,N;
void ins(int a,int b,int c,int d){
	M++;
	assert(M<maxm);
	to[M]=b;
	cap[M]=c;
	cos[M]=d;
	nex[M]=h[a];
	h[a]=M;
}
void add(int a,int b,int c,int d){
	ins(a,b,c,d);
	ins(b,a,0,-d);
}
int dis[maxn];
struct pr{
	int x,d;
	pr(int u=0):x(u),d(dis[u]){}
}t;
bool operator<(pr a,pr b){return a.d>b.d;}
priority_queue<pr>q;
int sum,cost;
bool bfs(){
	int x,i;
	memset(dis,127,(N+1)<<2);
	dis[T]=0;
	q.push(T);
	while(!q.empty()){
		t=q.top();
		q.pop();
		x=t.x;
		if(t.d!=dis[x])continue;
		for(i=h[x];i;i=nex[i]){
			if(cap[i^1]&&dis[x]-cos[i]<dis[to[i]]){
				dis[to[i]]=dis[x]-cos[i];
				q.push(to[i]);
			}
		}
	}
	sum+=dis[S];
	for(x=1;x<=N;x++){
		for(i=h[x];i;i=nex[i])cos[i]+=dis[to[i]]-dis[x];
	}
	return dis[S]!=dis[0];
}
bool aug[maxn];
int dfs(int x,int f){
	if(!f)return 0;
	if(x==T){
		cost+=f*sum;
		return f;
	}
	int i,t,us=0;
	aug[x]=1;
	for(i=h[x];i&&f;i=nex[i]){
		if(cap[i]&&!cos[i]&&!aug[to[i]]){
			t=dfs(to[i],min(f,cap[i]));
			cap[i]-=t;
			cap[i^1]+=t;
			us+=t;
			f-=t;
		}
	}
	if(!f)aug[x]=0;
	return us;
}
int mcmf(){
	int w,s=0;
	do{
		do{
			memset(aug,0,N+1);
			w=dfs(S,inf);
			s+=w;
		}while(w);
	}while(bfs());
	return s;
}
int n,m;
int l[310][20],r[310][20];
int now;
struct seg{
	int id[1210],fl,fr;
	void build(int l,int r,int x){
		id[x]=++N;
		assert(N<maxn);
		if(l==r)return add(id[x],(l-1)*m+now+n*m,inf,0);
		int mid=(l+r)>>1;
		build(l,mid,x<<1);
		build(mid+1,r,x<<1|1);
		add(id[x],id[x<<1],inf,fl*(r-mid));
		add(id[x],id[x<<1|1],inf,fr*(mid+1-l));
	}
	void build(int l,int r){
		fl=l;
		fr=r;
		build(1,n,1);
	}
	void query(int L,int R,int p,int l,int r,int x){
		if(L<=l&&r<=R)return add(now,id[x],inf,2*(fl?p-r:l-p));
		int mid=(l+r)>>1;
		if(L<=mid)query(L,R,p,l,mid,x<<1);
		if(mid<R)query(L,R,p,mid+1,r,x<<1|1);
	}
}tr[21];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",l[i]+j);
			l[i][j]++;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",r[i]+j);
			r[i][j]++;
		}
	}
	S=2*n*m+1;
	N=T=S+1;
	now=0;
	for(i=1;i<=m;i++){
		now++;
		tr[i].build(2,0);
	}
	now=0;
	for(i=m+1;i<=m*2;i++){
		now++;
		tr[i].build(0,2);
	}
	for(i=1;i<=n*m;i++)add(S,i,1,0);
	for(i=n*m+1;i<=2*n*m;i++)add(i,T,1,0);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			now=(i-1)*m+j;
			if(l[i][j]<i)tr[j].query(l[i][j],min(i-1,r[i][j]),i,1,n,1);
			if(l[i][j]<=i&&i<=r[i][j])add(now,now+n*m,inf,0);
			if(i<r[i][j])tr[j+m].query(max(i+1,l[i][j]),r[i][j],i,1,n,1);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<m;j++){
			now=(i-1)*m+j+n*m;
			add(now,now+1,inf,1);
			add(now+1,now,inf,1);
		}
		add((i-1)*m+1+n*m,i*m+n*m,inf,1);
		add(i*m+n*m,(i-1)*m+1+n*m,inf,1);
	}
	if(mcmf()!=n*m)
		puts("no solution");
	else
		printf("%d",cost);
}
