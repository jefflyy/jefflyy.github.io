#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
char s[200010];
int a[200010],st[200010],ed[200010],ans[200010],M,lb;
vector<int>in[200010];
int p[200010],N;
int main(){
	int n,i,j,sum,tmp;
	bool flag;
	scanf("%d%s",&n,s+1);
	a[0]=1;
	for(i=1;s[i];i++)a[i]=s[i]-'0';
	n<<=1;
	for(i=0;i<n;i++){
		if(!a[i]&&a[(i+1)%n]){
			M++;
			st[M]=i;
			for(j=(i+1)%n;a[j];j=(j+1)%n){
				if(a[(j+1)%n])in[M].push_back(j);
			}
			ed[M]=(j-1+n)%n;
		}
	}
	#define wa {puts("No");return 0;}
	if(!M){
		n>>=1;
		if(n&1)wa
		puts("Yes");
		for(i=1;i<=n;i+=2)printf("%d %d %d %d ",i,i+1,i,i+1);
		return 0;
	}
	sum=0;
	for(i=1;i<=M;i++)sum+=in[i].size();
	if(sum&1)wa
	if(sum&2){
		tmp=0;
		for(i=1;i<=M;i++)tmp+=!in[i].empty();
		if(tmp==1)wa
		for(i=1;in[i].empty();i++);
		for(j=i+1;in[j].empty();j++);
		swap(ed[i],ed[j]);
		ans[*in[i].rbegin()]=ans[*in[j].rbegin()]=++lb;
		in[i].pop_back();
		in[j].pop_back();
	}
	for(i=1;i<M;i++)ans[ed[i]]=ans[st[i+1]]=++lb;
	ans[ed[M]]=ans[st[1]]=++lb;
	for(i=1;i<=M;i++){
		for(int x:in[i])p[++N]=x;
	}
	for(i=1;i<=N;i+=4){
		ans[p[i]]=ans[p[i+2]]=++lb;
		ans[p[i+1]]=ans[p[i+3]]=++lb;
	}
	flag=0;
	for(i=0;i<n;i++){
		if(!ans[i]){
			flag=!flag;
			if(flag)lb++;
			ans[i]=lb;
		}
	}
	puts("Yes");
	for(i=0;i<n;i++)printf("%d ",ans[i]);
}
