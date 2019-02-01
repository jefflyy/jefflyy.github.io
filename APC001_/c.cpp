#include<stdio.h>
#include<string.h>
int c[100010];
char s[10];
int getn(){
	int n;
	scanf("%d",&n);
	return n;
}
int get(int x){
	if(~c[x])return c[x];
	printf("%d\n",x);
	fflush(stdout);
	scanf("%s",s);
	if(s[0]=='V')throw 0;
	return c[x]=s[0]=='M';
}
int main(){
	int n,l,r,mid;
	memset(c,-1,sizeof(c));
	n=getn();
	try{
		l=0;
		r=n-1;
		while(r-l>2){
			mid=(l+r)>>1;
			if((mid-l+1)&1){
				if(get(l)^get(mid))
					r=mid;
				else
					l=mid;
			}else{
				if(get(mid+1)^get(r))
					l=mid+1;
				else
					r=mid+1;
			}
		}
		while(l<=r)get(l++);
	}catch(int e){}
}
