#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
const int pr[]={2,3,5,7},mx=1e9;
int p[6010],M;
void dfs(int x,int num){
	if(x>3){
		p[++M]=num;
		return;
	}
	dfs(x+1,num);
	while(num<=mx/pr[x]){
		num*=pr[x];
		dfs(x+1,num);
	}
}
ll f[20][6010],pw[20],l,r;
ll dfs(ll pre,int n,ll pr){
	ll mx,mn,s;
	int i,t;
	t=0;
	mn=pre*pw[n];
	mx=mn+pw[n]-1;
	if(mx<l||mn>r)return 0;
	if(n==0)return pr==1;
	if(l<=mn&&mx<=r){
		t=lower_bound(p+1,p+M+1,pr)-p;
		if(~f[n][t])return f[n][t];
	}
	s=0;
	if(!pre&&n>1)s=dfs(0,n-1,pr);
	for(i=1;i<10;i++){
		if(pr%i==0)s+=dfs(pre*10+i,n-1,pr/i);
	}
	if(l<=mn&&mx<=r)f[n][t]=s;
	return s;
}
int main(){
	dfs(0,1);
	sort(p+1,p+M+1);
	pw[0]=1;
	int i;
	ll L,R,s;
	for(i=1;i<=18;i++)pw[i]=pw[i-1]*10;
	scanf("%I64d%I64d",&L,&R);
	memset(f,-1,sizeof(f));
	s=0;
	for(i=1;i<=M;i++){
		l=(L+p[i]-1)/p[i];
		r=R/p[i];
		if(l<=r)s+=dfs(0,18,p[i]);
	}
	printf("%I64d",s);
}
