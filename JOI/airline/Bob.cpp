#include"Boblib.h"
#include<assert.h>
namespace bob{
	int h[1010],nex[510010],to[510010],M;
	int in[1010];
	void add(int a,int b){
		M++;
		to[M]=b;
		nex[M]=h[a];
		h[a]=M;
		in[b]++;
	}
	bool check(int x,int y){
		for(int i=h[x];i;i=nex[i]){
			if(to[i]==y)return 1;
		}
		return 0;
	}
	int q[1010],id[1010];
	struct edge{
		int x,y;
		edge(){}
		edge(int x,int y):x(x),y(y){}
	}e[500010];
	int E;
}
void Bob(int n,int m,int a[],int b[]){
	using namespace bob;
	int head,tail,x,i;
	bool flag;
	for(i=0;i<m;i++)add(a[i],b[i]);
	head=0;
	tail=0;
	for(i=0;i<n;i++){
		if(!in[i])q[tail++]=i;
	}
	assert(tail==1);
	while(head<tail){
		x=q[head++];
		for(i=h[x];i;i=nex[i]){
			if(!--in[to[i]])q[tail++]=to[i];
		}
	}
	for(i=0;i<n;i++)id[q[i]]=i;
	for(x=0;x<n;x++){
		if(id[x]==n-1)continue;
		flag=check(x,q[n-1]);
		for(i=h[x];i;i=nex[i]){
			if(to[i]==q[n-1])continue;
			if(id[to[i]]!=id[x]+1||flag){
				e[E++]=edge(id[x],id[to[i]]);
			}
		}
	}
	InitMap(n-1,E);
	for(i=0;i<E;i++)MakeMap(e[i].x,e[i].y);
}
