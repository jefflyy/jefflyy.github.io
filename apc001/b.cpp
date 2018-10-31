#include<stdio.h>
typedef long long ll;
int a[10010],b[10010];
int main(){
	int n,i;
	ll s;
	scanf("%d",&n);
	s=0;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		s-=a[i];
	}
	for(i=1;i<=n;i++){
		scanf("%d",b+i);
		s+=b[i];
	}
	for(i=1;i<=n;i++){
		if(a[i]<b[i])s-=(b[i]-a[i]+1)/2;
	}
	puts(s<0?"No":"Yes");
}
