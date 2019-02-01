#include<stdio.h>
int h[100010],nex[200010],to[200010],M;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
int d[100010],f[100010];
void dfs(int fa,int x){
	int i,c;
	c=0;
	for(i=h[x];i;i=nex[i]){
		if(to[i]!=fa){
			dfs(x,to[i]);
			f[x]+=f[to[i]];
			c+=!f[to[i]];
		}
	}
	if(c>1)f[x]+=c-1;
}
int main(){
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		x++;
		y++;
		add(x,y);
		add(y,x);
		d[x]++;
		d[y]++;
	}
	for(i=1;i<=n;i++){
		if(d[i]>2)break;
	}
	if(i>n){
		putchar('1');
		return 0;
	}
	dfs(0,i);
	printf("%d",f[i]);
}
