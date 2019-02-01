#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int h[100010],nex[200010],to[200010],M;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
bool vis[100010];
int v[100010],p[100010],pa[100010],ma;
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	p[++M]=v[x];
	for(int i=h[x];i;i=nex[i])dfs(to[i]);
}
int main(){
	int n,m,i,j,x,y,cnt;
	ll ans;
	scanf("%d%d",&n,&m);
	if(2*(n-m-1)>n){
		puts("Impossible");
		return 0;
	}
	ans=0;
	cnt=2*(n-m-1);
	for(i=1;i<=n;i++)scanf("%d",v+i);
	while(m--){
		scanf("%d%d",&x,&y);
		x++;
		y++;
		add(x,y);
		add(y,x);
	}
	for(i=1;i<=n&&cnt;i++){
		if(!vis[i]){
			M=0;
			dfs(i);
			sort(p+1,p+M+1);
			ans+=p[1];
			for(j=2;j<=M;j++)pa[++ma]=p[j];
			cnt--;
		}
	}
	sort(pa+1,pa+ma+1);
	for(i=1;i<=cnt;i++)ans+=pa[i];
	printf("%lld",ans);
}
