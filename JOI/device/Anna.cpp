#include"Annalib.h"
#include<string.h>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
namespace a{
	string mp[4]={"010","101","011","111"};
	int b[160];
}
void Anna(int N,ll X,int K,int P[]){
	using namespace a;
	int i,c,t;
	string s;
	memset(b,0,sizeof(b));
	for(i=0;i<K;i++)b[P[i]]=1;
	for(i=0;i<N;i+=3){
		c=b[i]+b[i+1]+b[i+2];
		if(c==0||(c==1&&b[i]&&(~X&1))){
			t=X&1;
			X>>=1;
			t|=(X&1)<<1;
			X>>=1;
			s+=mp[t];
		}else if(c==1){
			s+=X&1?(b[i+2]?"110":"001"):"100";
			X>>=1;
		}else
			s+="000";
	}
	for(i=0;i<N;i++)Set(i,s[i]-'0');
}
