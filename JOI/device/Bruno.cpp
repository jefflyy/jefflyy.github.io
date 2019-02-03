#include"Brunolib.h"
#include<string>
using namespace std;
typedef long long ll;
namespace b{
	string mp[8]={"","0","00","1","1","10","01","11"};
}
ll Bruno(int N,int A[]){
	using namespace b;
	int i;
	ll x;
	string s;
	for(i=0;i<N;i+=3)s+=mp[A[i]|A[i+1]<<1|A[i+2]<<2];
	x=0;
	for(i=0;i<60;i++)x|=(ll)(s[i]-'0')<<i;
	return x;
}
