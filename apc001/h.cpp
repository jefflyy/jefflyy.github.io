#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int ans[25010],op;
int fa[2010],dep[2010],a[2010],ch[2010],dn[2010],up[2010],rk[2010],so[2010],bl[2010],M;
bool del[2010],us[2010];
void rot(int x){
	ans[++op]=x;
	int v=a[x];
	a[x]=a[1];
	for(x=fa[x];x;x=fa[x])swap(v,a[x]);
}
int main(){
	int n,i,j,cnt;
	bool flag;
	scanf("%d",&n);
	dep[1]=1;
	for(i=2;i<=n;i++){
		scanf("%d",fa+i);
		fa[i]++;
		ch[fa[i]]++;
		dep[i]=dep[fa[i]]+1;
	}
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		a[i]++;
	}
	while(1){
		flag=1;
		for(i=1;i<=n;i++){
			if(a[i]!=i){
				flag=0;
				break;
			}
		}
		if(flag)break;
		M=0;
		for(i=1;i<=n;i++){
			if(!del[i]&&ch[i]==0){
				M++;
				dn[M]=i;
				for(j=i;fa[j]&&ch[fa[j]]==1;j=fa[j]);
				up[M]=j;
				so[M]=0;
				cnt=0;
				for(j=i;dep[j]>=dep[up[M]];j=fa[j]){
					rk[j]=++cnt;
					bl[j]=M;
				}
			}
		}
		memset(us,0,sizeof(us));
		while(1){
			flag=1;
			for(i=1;i<=M;i++){
				for(j=dn[i];dep[j]>=dep[up[i]];j=fa[j]){
					if(a[j]!=j){
						flag=0;
						break;
					}
				}
				if(!flag)break;
			}
			if(flag)break;
			us[a[1]]=1;
			if(bl[a[1]]){//insert it to a chain
				i=bl[a[1]];
				if(!so[i]){
					rot(dn[i]);
					so[i]=dn[i];
				}else{
					for(j=dn[i];dep[j]>=dep[so[i]]&&rk[a[j]]<rk[a[1]];j=fa[j]);
					rot(j);
					so[i]=fa[so[i]];
				}
			}else{
				j=0;
				for(i=1;i<=n;i++){
					if(!del[i]&&!us[a[i]]&&dep[i]>dep[j])j=i;
				}
				rot(j);
			}
		}
		for(i=1;i<=M;i++){
			for(j=dn[i];dep[j]>=dep[up[i]];j=fa[j])del[j]=1;
			ch[fa[up[i]]]--;
		}
	}
	printf("%d\n",op);
	for(i=1;i<=op;i++)printf("%d\n",ans[i]-1);
}
