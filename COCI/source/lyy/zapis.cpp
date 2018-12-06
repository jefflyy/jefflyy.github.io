#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e5;
bool flag;
int mul(int a,int b){
	if((ll)a*b>=mod)flag=1;
	return(ll)a*b%mod;
}
char s[210];
int f[210][210];
bool op(char a){
	return a=='?'||a=='('||a=='['||a=='{';
}
bool cl(char a){
	return a=='?'||a==')'||a==']'||a=='}';
}
bool pr(char a,char b){
	if(a=='?')return cl(b);
	if(b=='?')return op(a);
	if(a>b)swap(a,b);
	return(a=='('&&b==')')||(a=='['&&b==']')||(a=='{'&&b=='}');
}
int dp(int l,int r){
	if(l>r)return 1;
	if(~f[l][r])return f[l][r];
	int&res=f[l][r],i;
	res=0;
	if(!op(s[l]))return 0;
	for(i=l+1;i<=r;i+=2){
		if(pr(s[l],s[i]))res+=mul(dp(l+1,i-1),dp(i+1,r))*(s[l]=='?'&&s[i]=='?'?3:1);
	}
	if(res>=mod)flag=1;
	return res%=mod;
}
int main(){
	int n;
	scanf("%d%s",&n,s+1);
	memset(f,-1,sizeof(f));
	printf(flag?"%05d":"%d",dp(1,n));
}
