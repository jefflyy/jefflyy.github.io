#include"Alicelib.h"
#include<algorithm>
using namespace std;
namespace alice{
	int h[1010],nex[500010],to[500010],M;
	void add(int a,int b){
		M++;
		to[M]=b;
		nex[M]=h[a];
		h[a]=M;
	}
	bool check(int x,int y){
		for(int i=h[x];i;i=nex[i]){
			if(to[i]==y)return 1;
		}
		return 0;
	}
	struct edge{
		int x,y;
		edge(){}
		edge(int x,int y):x(x),y(y){}
	}e[510010];
	int E;
}
void Alice(int n,int m,int a[],int b[]){
	using namespace alice;
	int i;
	for(i=0;i<m;i++){
		if(a[i]>b[i])swap(a[i],b[i]);
		add(a[i],b[i]);
		e[E++]=edge(a[i],b[i]);
	}
	for(i=0;i<n;i++)e[E++]=edge(i,check(i,i+1)?n:i+1);
	InitG(n+1,E);
	for(i=0;i<E;i++)MakeG(i,e[i].x,e[i].y);
}
