#include<stdio.h>
#include<algorithm>
using namespace std;
int x[300010],y[300010],n;
int h[300010],nex[600010],to[600010],M;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
int dis[300010];
void dfs(int fa,int x){
	for(int i=h[x];i;i=nex[i]){
		if(to[i]!=fa){
			dis[to[i]]=dis[x]+1;
			dfs(x,to[i]);
		}
	}
}
int dia(){
	int i,p;
	for(i=1;i<n;i++){
		add(x[i],y[i]);
		add(y[i],x[i]);
	}
	p=0;
	dfs(0,1);
	for(i=1;i<=n;i++){
		if(dis[i]>dis[p])p=i;
	}
	dis[p]=0;
	dfs(0,p);
	p=0;
	for(i=1;i<=n;i++)p=max(p,dis[i]);
	return p;
}
int fa[300010];
int get(int x){return fa[x]==x?x:(fa[x]=get(fa[x]));}
int main(int argc,char**args){
	FILE*in,*out,*ans,*res,*rep;
	in=fopen(args[1],"r");
	out=fopen(args[2],"r");
	ans=fopen(args[3],"r");
	res=fopen(args[5],"w");
	rep=fopen(args[6],"w");
	#define ok(x) (0<x&&x<=n)
	#define ass(b,s) {if(!(b)){fprintf(rep,s);fprintf(res,"0");return 0;}}
	int i,std,a,b,c,d,p;
	fscanf(in,"%d",&n);
	for(i=1;i<n;i++){
		fscanf(in,"%d%d",x+i,y+i);
		if(x[i]>y[i])swap(x[i],y[i]);
	}
	fscanf(ans,"%d",&std);
	ass(fscanf(out,"%d",&a)==1,"invalid output")
	ass(std==a,"wrong answer")
	ass(fscanf(out,"%d%d%d%d",&a,&b,&c,&d)==4,"invalid output")
	ass(ok(a)&&ok(b)&&ok(c)&&ok(d),"invalid output")
	for(i=1;i<=n;i++)fa[i]=i;
	if(a>b)swap(a,b);
	p=0;
	for(i=1;i<n;i++){
		if(a==x[i]&&b==y[i])
			p=i;
		else
			fa[get(x[i])]=get(y[i]);
	}
	ass(p,"invalid cut")
	ass(get(c)!=get(d),"invalid link")
	x[p]=c;
	y[p]=d;
	ass(dia()==std,"incorrect tree");
	fprintf(rep,"ok");
	fprintf(res,args[4]);
	return 0;
}
