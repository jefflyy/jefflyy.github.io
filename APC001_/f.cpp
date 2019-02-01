#include<stdio.h>
#include<algorithm>
using namespace std;
int lowbit(int x){return x&-x;}
int a[100010],c[20],v[32768],s[32768],f[32768];
int main(){
	int n,i,j,x,y,z,res,M;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x+1]^=z;
		a[y+1]^=z;
	}
	for(i=1;i<=n;i++)c[a[i]]++;
	res=M=0;
	res+=c[0];
	for(i=1;i<16;i++){
		res+=c[i]/2;
		if(c[i]&1)v[1<<(M++)]=i;
	}
	for(i=1;i<1<<M;i++)s[i]=s[i^lowbit(i)]^v[lowbit(i)];
	for(i=1;i<1<<M;i++){
		if(s[i]==0){
			for(j=i;j;j=(j-1)&i){
				if(s[j]==0)f[i]=max(f[i],f[i^j]+1);
			}
		}
	}
	printf("%d",n-(res+f[(1<<M)-1]));
}
