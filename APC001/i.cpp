#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=1000000007;
const int go[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int mul(int a,int b){return(ll)a*b%mod;}
int x[40],y[40],sx[1000010],sy[1000010],ix[1000010],iy[1000010],mx,my;
bool bx[1000010],by[1000010],mp[70][70];
int dis[70][70],vx[70],vy[70];
struct pr{
	int x,y;
	pr(int x=0,int y=0):x(x),y(y){}
}q[4010];
bool ok(int x,int y){
	return 0<x&&x<=mx&&0<y&&y<=my&&!mp[x][y];
}
void bfs(pr t){
	int head,tail,x,y,i;
	memset(dis,63,sizeof(dis));
	head=tail=1;
	q[1]=t;
	dis[t.x][t.y]=0;
	while(head<=tail){
		t=q[head++];
		for(i=0;i<4;i++){
			x=t.x+go[i][0];
			y=t.y+go[i][1];
			if(ok(x,y)&&dis[t.x][t.y]+1<dis[x][y]){
				dis[x][y]=dis[t.x][t.y]+1;
				q[++tail]=pr(x,y);
			}
		}
	}
}
int main(){
	int h,w,n,i,j,k,l,res,tmp;
	scanf("%d%d%d",&h,&w,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",x+i,y+i);
		bx[++x[i]]=1;
		by[++y[i]]=1;
		sx[x[i]]++;
		sy[y[i]]++;
	}
	res=0;
	for(i=1;i<=h;i++)sx[i]+=sx[i-1];
	for(i=1;i<=w;i++)sy[i]+=sy[i-1];
	ix[1]=++mx;
	for(i=2;i<=h;i++){
		if(!bx[i]&&!bx[i-1]){
			ix[i]=ix[i-1];
			(res+=mul(mul(i-1,w)-sx[i-1],mul(h-i+1,w)-(sx[h]-sx[i-1])))%=mod;
		}else
			ix[i]=++mx;
	}
	iy[1]=++my;
	for(i=2;i<=w;i++){
		if(!by[i]&&!by[i-1]){
			iy[i]=iy[i-1];
			(res+=mul(mul(i-1,h)-sy[i-1],mul(w-i+1,h)-(sy[w]-sy[i-1])))%=mod;
		}else
			iy[i]=++my;
	}
	for(i=1;i<=h;i=j){
		for(j=i;ix[j]==ix[i];j++);
		vx[ix[i]]=j-i;
	}
	for(i=1;i<=w;i=j){
		for(j=i;iy[j]==iy[i];j++);
		vy[iy[i]]=j-i;
	}
	for(i=1;i<=n;i++)mp[ix[x[i]]][iy[y[i]]]=1;
	for(i=1;i<=mx;i++){
		for(j=1;j<=my;j++){
			if(!mp[i][j]){
				bfs(pr(i,j));
				tmp=0;
				for(k=i;k<=mx;k++){
					for(l=1;l<=my;l++){
						if((k>i||l>j)&&!mp[k][l])(tmp+=mul(dis[k][l],mul(vx[k],vy[l])))%=mod;
					}
				}
				(res+=mul(tmp,mul(vx[i],vy[j])))%=mod;
			}
		}
	}
	printf("%d",(res+mod)%mod);
}
