#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
const int go[4][2]={{0,1},{1,0},{0,-1},{-1,0}},inf=1e9,maxv=1e6;
bool fmin(int&a,int b){
	if(b<a){
		a=b;
		return 1;
	}
	return 0;
}
int a[240][240],c[240][240],n,m,k,N;
int map[240];
int f[32][240];
int p(int x,int y){
	return(x-1)*m+y;
}
int q[10010],head,tail;
bool inq[10010];
bool ok(int x,int y){
	return 0<x&&x<=n&&0<y&&y<=m&&~c[x][y];
}
int v[240];
void bfs(int*dis){
	int t,x,y,tx,ty,i;
	while(head<=tail){
		inq[t=q[head++]]=0;
		x=(t-1)/m+1;
		y=(t-1)%m+1;
		for(i=0;i<4;i++){
			tx=x+go[i][0];
			ty=y+go[i][1];
			if(ok(tx,ty)&&fmin(dis[p(tx,ty)],dis[t]+v[p(tx,ty)])&&!inq[p(tx,ty)])inq[q[++tail]=p(tx,ty)]=1;
		}
	}
}
int sttree(){
	int i,j,s,t,mn;
	for(i=0;i<1<<k;i++){
		for(j=1;j<=N;j++)f[i][j]=inf;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(~c[i][j])f[1<<map[c[i][j]]][p(i,j)]=v[p(i,j)];
		}
	}
	for(s=0;s<1<<k;s++){
		head=1;
		tail=0;
		for(i=1;i<=N;i++){
			for(t=s;t;t=(t-1)&s)fmin(f[s][i],f[t][i]+f[s-t][i]-v[i]);
			if(f[s][i]!=inf)inq[q[++tail]=i]=1;
		}
		bfs(f[s]);
	}
	mn=inf;
	for(i=1;i<=N;i++)fmin(mn,f[(1<<k)-1][i]);
	return mn;
}
void solve(int&res1,int&res2){
	int i,bl,tmp,l,r,mid,ans;
	for(i=1;i<=N;i++)map[i]=rand()%k;
	for(i=1;i<=N;i++)v[i]=1;
	bl=sttree();
	if(bl!=inf&&bl<=res1){
		tmp=(bl+1)/2;
		l=0;
		r=maxv;
		ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			for(i=1;i<=N;i++)v[i]=a[(i-1)/m+1][(i-1)%m+1]<=mid?maxv-1:maxv;
			if(sttree()-bl*maxv<=-tmp){
				ans=mid;
				r=mid-1;
			}else
				l=mid+1;
		}
		assert(~ans);
		bl<res1?res2=ans:fmin(res2,ans);
		res1=bl;
	}
}
void work(){
	int i,j,tms;
	int res1,res2;
	scanf("%d%d%d",&n,&m,&k);
	N=n*m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)scanf("%d",c[i]+j);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)scanf("%d",a[i]+j);
	}
	tms=200;
	res1=res2=inf;
	while(tms--)solve(res1,res2);
	if(res1==inf)res1=res2=-1;
	printf("%d %d\n",res1,res2);
}
int main(){
	srand(19260817);
	int T;
	scanf("%d",&T);
	while(T--)work();
}
