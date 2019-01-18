#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
const int mod=998244353,T=1e4,len=16,inf=2147483647;
int mul(int a,int b){return(ll)a*b%mod;}
int pow(int a,int b){
	int s=1;
	while(b){
		if(b&1)s=mul(s,a);
		a=mul(a,a);
		b>>=1;
	}
	return s;
}
int pr[T+10],d[T+10];
bool np[T+10];
void sieve(){
	int i,j,M=0;
	d[1]=1;
	for(i=2;i<=T;i++){
		if(!np[i])d[pr[++M]=i]=i;
		for(j=1;j<=M&&i*pr[j]<=T;j++){
			np[i*pr[j]]=1;
			d[i*pr[j]]=d[i]%pr[j]?d[i]*pr[j]:d[i]/pr[j];
			if(i%pr[j]==0)break;
		}
	}
}
int cu(unsigned x){
	#define bc __builtin_ctz
	return x&65535?bc(x&65535):bc(x>>16)+16;
}
int cl(ll x){
	return x&4294967295ll?cu(x&4294967295ll):cu(x>>32)+32;
}
struct bitset{
	ll a[len];
	void reset(){
		for(int i=0;i<len;i++)a[i]=0;
	}
	int lowbit(){
		for(int i=0;i<len;i++){
			if(a[i])return cl(a[i])+(i<<6);
		}
		return-1;
	}
	void set(int k){
		a[k>>6]|=1ull<<(k&63);
	}
	int get(int k){
		return a[k>>6]>>(k&63)&1;
	}
	void operator^=(const bitset&b){
		for(int i=0;i<len;i++)a[i]^=b.a[i];
	}
	bool any(){
		for(int i=0;i<len;i++){
			if(a[i])return 1;
		}
		return 0;
	}
	void out(){
		for(int i=0;i<30;i++)putchar(a[0]>>i&1?'#':' ');
		putchar('\n');
	}
}b[1010];
int M;
bool us[1010];
void work(){
	int l,r,i,j,s,t,mn,p;
	bool flag;
	scanf("%d%d",&l,&r);
	M=0;
	for(j=1;pr[j]<=r;j++){
		flag=0;
		for(i=l;i<=r;i++){
			if(d[i]%pr[j]==0){
				flag=1;
				break;
			}
		}
		if(flag){
			b[++M].reset();
			for(i=l;i<=r;i++){
				if(d[i]%pr[j]==0)b[M].set(i-l);
			}
		}
	}
	memset(us,0,sizeof(us));
	s=0;
	while(1){
		mn=inf;
		p=0;
		for(i=1;i<=M;i++){
			if(!us[i]){
				t=b[i].lowbit();
				if(t<mn){
					mn=t;
					p=i;
				}
			}
		}
		if(!p)break;
		s++;
		for(i=1;i<=M;i++){
			if(!us[i]&&i!=p&&b[i].lowbit()==mn)b[i]^=b[p];
		}
		us[p]=1;
		for(i=1;i<=M;i++){
			if(!us[i]&&!b[i].any())us[i]=1;
		}
	}
	printf("%d\n",pow(2,r-l+1-s));
}
int main(){
	sieve();
	int T;
	scanf("%d",&T);
	while(T--)work();
}
