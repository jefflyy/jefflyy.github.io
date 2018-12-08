#include<stdio.h>
#include<algorithm>
using namespace std;
int h[100010],nex[1000010],to[1000010],M;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
struct tree{
	int h[200010],nex[200010],to[200010],M;
	void add(int a,int b){
		M++;
		to[M]=b;
		nex[M]=h[a];
		h[a]=M;
	}
	int fa[200010][18],dep[200010],in[200010],ou[200010];
	void dfs(int x){
		dep[x]=dep[fa[x][0]]+1;
		in[x]=++M;
		for(int i=h[x];i;i=nex[i]){
			fa[to[i]][0]=x;
			dfs(to[i]);
		}
		ou[x]=M;
	}
	void gao(int n){
		int i,j;
		M=0;
		dfs(1);
		for(j=1;j<18;j++){
			for(i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	int jump(int x,int k){
		for(int i=17;i>=0;i--){
			if(k>>i&1)x=fa[x][i];
		}
		return x;
	}
	int near(int x,int y){
		return jump(x,dep[x]-dep[y]-1);
	}
	bool sub(int x,int y){
		return in[x]<=in[y]&&in[y]<=ou[x];
	}
}t1,t2;
int dfn[100010],low[100010],st[100010],tp,N;
bool b[100010];
void dfs(int fa,int x){
	int i,y;
	dfn[x]=low[x]=++M;
	st[++tp]=x;
	for(i=h[x];i;i=nex[i]){
		if(!dfn[to[i]]){
			t1.add(x,to[i]);
			dfs(x,to[i]);
			low[x]=min(low[x],low[to[i]]);
			if(low[to[i]]>dfn[x])b[to[i]]=1;
			if(low[to[i]]>=dfn[x]){
				N++;
				do{
					t2.add(N,y=st[tp--]);
				}while(y!=to[i]);
				t2.add(x,N);
			}
		}else if(to[i]!=fa)
			low[x]=min(low[x],dfn[to[i]]);
	}
}
int main(){
	int n,m,i,x,y,a,b;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	M=0;
	N=n;
	dfs(0,1);
	t1.gao(n);
	t2.gao(N);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&i,&x,&y);
		if(i==1){
			scanf("%d%d",&a,&b);
			if(t1.fa[a][0]==b||t1.fa[b][0]==a){
				if(t1.fa[a][0]==b)swap(a,b);
				puts(::b[b]&&(t1.sub(b,x)^t1.sub(b,y))?"no":"yes");
			}else
				puts("yes");
		}else{
			scanf("%d",&a);
			if(t2.sub(a,x)^t2.sub(a,y))
				puts("no");
			else if(t2.sub(a,x))
				puts(t2.near(x,a)==t2.near(y,a)?"yes":"no");
			else
				puts("yes");
		}
	}
}
