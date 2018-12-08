#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=9223372036854775807ll;
void fmin(ll&a,ll b){
	if(b>0&&b<a)a=b;
}
ll f[100010];
int a[100010],b[100010];
ll gao(int l,int r){
	int p[3],i;
	ll s,t;
	for(i=l;i<=r;i++)p[i-l]=i;
	s=inf;
	do{
		t=0;
		for(i=0;i<=r-l;i++){
			if(a[i+l]==b[p[i]]){
				t=inf;
				break;
			}
			t+=abs(a[i+l]-b[p[i]]);
		}
		fmin(s,t);
	}while(next_permutation(p,p+r-l+1));
	return s;
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++){
		f[i]=inf;
		fmin(f[i],f[i-1]+gao(i,i));
		if(i>1)fmin(f[i],f[i-2]+gao(i-1,i));
		if(i>2)fmin(f[i],f[i-3]+gao(i-2,i));
	}
	printf("%I64d",f[n]);
}
