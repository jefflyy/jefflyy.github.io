#include<stdio.h>
#include<algorithm>
#include<bitset>
#include<map>
using namespace std;
typedef long long ll;
typedef bitset<450> bs;
const int T=1e7,sq=3162,mod=998244353;
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
int pr[T+10],d[T+10],md[T+10],M;
bool np[T+10];
void sieve(){
	int i,j;
	d[1]=md[1]=1;
	for(i=2;i<=T;i++){
		if(!np[i]){
			pr[++M]=i;
			d[i]=md[i]=i;
		}
		for(j=1;j<=M&&i*pr[j]<=T;j++){
			np[i*pr[j]]=1;
			d[i*pr[j]]=d[i]%pr[j]?d[i]*pr[j]:d[i]/pr[j];
			md[i*pr[j]]=max(md[i],pr[j]);
			if(i%pr[j]==0)break;
		}
	}
}
bs b[450],t;
map<int,bs>mp;
void gao(int l,int r){
	int i,s;
	s=0;
	for(i=1;i<=664579;i++)s+=((l-1)/pr[i]<r/pr[i]);
	printf("%d\n",pow(2,r-l+1-s));
}
void work(){
	int l,r,i,j,s,cnt;
	scanf("%d%d",&l,&r);
	if(r-l>=6000)return gao(l,r);
	for(i=1;i<=M;i++)b[i].reset();
	mp.clear();
	s=0;
	cnt=0;
	for(i=l;i<=r;i++){
		if((md[i]<=sq||mp.count(md[i]))&&cnt==M)continue;
		t.reset();
		for(j=1;j<=M;j++){
			if(d[i]%pr[j]==0)t.set(j);
		}
		if(md[i]>sq){
			if(mp.count(md[i]))
				t^=mp[md[i]];
			else{
				mp[md[i]]=t;
				s++;
				continue;
			}
		}
		for(j=1;j<=M;j++){
			if(t[j]){
				if(b[j].any())
					t^=b[j];
				else{
					b[j]=t;
					cnt++;
					break;
				}
			}
		}
	}
	s+=cnt;
	printf("%d\n",pow(2,r-l+1-s));
}
int main(){
	sieve();
	M=446;
	int T;
	scanf("%d",&T);
	while(T--)work();
}
