#include<stdio.h>
#include<vector>
using namespace std;
typedef unsigned un;
const un B=316;
int h[100010],nex[200010],to[200010],M;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
struct pr{
	int x,v;
	pr(int x=0,int v=0):x(x),v(v){}
};
typedef vector<pr> vp;
pr c[B];
int v[100010];
un k;
void push(pr t){
	if(v[t.x]==M)return;
	v[t.x]=M;
	c[k++]=t;
}
void merge(vp&a,const vp&b){
	un an,bn,i,j;
	an=a.size();
	bn=b.size();
	k=0;
	M++;
	for(i=j=0;k<B&&(i<an||j<bn);){
		if(i==an||j==bn)
			push(j==bn?a[i++]:b[j++]);
		else
			push(a[i].v>b[j].v?a[i++]:b[j++]);
	}
	a=vp(c,c+k);
}
vp g[100010];
int f[100010];
int main(){
	int n,m,q,i,x,y;
	bool flag;
	scanf("%d%d%d",&n,&m,&q);
	while(m--){
		scanf("%d%d",&x,&y);
		add(y,x);
	}
	M=0;
	for(x=1;x<=n;x++){
		for(i=h[x];i;i=nex[i])merge(g[x],g[to[i]]);
		
		for(pr&t:g[x])t.v++;
		if(g[x].size()<B)g[x].push_back(pr(x,0));
	}
	while(q--){
		M++;
		scanf("%d%d",&x,&m);
		while(m--){
			scanf("%d",&y);
			v[y]=M;
		}
		flag=0;
		for(pr t:g[x]){
			if(v[t.x]!=M){
				printf("%d\n",t.v);
				flag=1;
				break;
			}
		}
		if(flag)continue;
		if(g[x].size()<B){
			puts("-1");
			continue;
		}
		for(y=1;y<=x;y++){
			f[y]=(v[y]==M?-1:0);
			for(i=h[y];i;i=nex[i]){
				if(~f[to[i]])f[y]=max(f[y],f[to[i]]+1);
			}
		}
		printf("%d\n",f[x]);
	}
}
