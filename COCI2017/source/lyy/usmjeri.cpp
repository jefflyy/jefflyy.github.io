#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int h[300010],nex[600010],to[600010],M;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
int fa[300010][19],dep[300010],in[300010],ou[300010];
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	in[x]=++M;
	for(int i=h[x];i;i=nex[i]){
		if(to[i]!=fa[x][0]){
			fa[to[i]][0]=x;
			dfs(to[i]);
		}
	}
	ou[x]=M;
}
int lca(int x,int y){
	int i;
	if(dep[x]<dep[y])swap(x,y);
	for(i=18;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	}
	if(x==y)return x;
	for(i=18;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int jump(int x,int k){
	for(int i=18;i>=0;i--){
		if(k>>i&1)x=fa[x][i];
	}
	return x;
}
struct pr{
	int x,y;
	pr(int a=0,int b=0){
		if(a>b)swap(a,b);
		x=a;
		y=b;
	}
};
bool operator<(pr a,pr b){return a.x==b.x?a.y<b.y:a.x<b.x;}
vector<pr>p[300010];
vector<pr>::iterator it;
int s[300010];
void chad(int x,int k){
	s[in[x]]++;
	s[in[jump(x,k)]]--;
}
struct graph{
	int h[300010],nex[600010],to[600010],M;
	void ins(int a,int b){
		M++;
		to[M]=b;
		nex[M]=h[a];
		h[a]=M;
	}
	void add(int a,int b){
		ins(a,b);
		ins(b,a);
	}
	int d[300010];
	bool dfs(int fa,int x){
		d[x]=d[fa]+1;
		for(int i=h[x];i;i=nex[i]){
			if(!d[to[i]]){
				if(dfs(x,to[i]))return 1;
			}else if(d[x]-d[to[i]]==2)
				return 1;
		}
		return 0;
	}
}g;
bool check(vector<pr>&v){
	for(pr t:v){
		g.add(t.x,t.y);
		g.d[t.x]=g.d[t.y]=0;
	}
	for(pr t:v){
		if(!g.d[t.x]&&g.dfs(0,t.x))return 1;
		if(!g.d[t.y]&&g.dfs(0,t.y))return 1;
	}
	for(pr t:v)g.h[t.x]=g.h[t.y]=0;
	g.M=0;
	return 0;
}
struct dsu{
	int fa[300010];
	int get(int x){return x==fa[x]?x:(fa[x]=get(fa[x]));}
	void merge(int x,int y){
		x=get(x);
		y=get(y);
		if(x!=y)fa[x]=y;
	}
}c,b;
void merge(int x,int y){
	x=c.get(x);
	y=c.get(y);
	while(x!=y){
		c.fa[x]=fa[x][0];
		b.merge(x,fa[x][0]);
		x=c.get(x);
	}
}
int main(){
	int n,m,i,j,x,y,z,res;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	M=0;
	dfs(1);
	for(j=1;j<19;j++){
		for(i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
	}
	for(i=1;i<=n;i++)c.fa[i]=b.fa[i]=i;
	while(m--){
		scanf("%d%d",&x,&y);
		z=lca(x,y);
		if(x==z||y==z){
			if(x!=z)swap(x,y);
			if(dep[y]-dep[x]>1){
				chad(y,dep[y]-dep[x]-1);
				merge(y,jump(y,dep[y]-dep[x]-1));
			}
		}else{
			p[z].push_back(pr(jump(x,dep[x]-dep[z]-1),jump(y,dep[y]-dep[z]-1)));
			if(dep[x]-dep[z]>1){
				chad(x,dep[x]-dep[z]-1);
				merge(x,jump(x,dep[x]-dep[z]-1));
			}
			if(dep[y]-dep[z]>1){
				chad(y,dep[y]-dep[z]-1);
				merge(y,jump(y,dep[y]-dep[z]-1));
			}
			b.merge(x,y);
		}
	}
	for(i=1;i<=M;i++)s[i]+=s[i-1];
	#define wa {puts("0");return 0;}
	for(i=1;i<=n;i++){
		#define sum(x) (s[ou[x]]-s[in[x]-1])
		for(pr t:p[i]){
			if(sum(t.x)&&sum(t.y))wa
		}
		if(check(p[i]))wa
	}
	res=1;
	for(i=2;i<=n;i++){
		if(b.fa[i]==i)(res<<=1)%=mod;
	}
	printf("%d",res);
}
