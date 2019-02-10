#include<stdio.h>
#include<algorithm>
#include<assert.h>
using namespace std;
typedef long long ll;
int R,C,n;
struct pr{
	int x,y;
	pr(int x=0,int y=0):x(x),y(y){}
}p[310];
bool operator<(pr a,pr b){return a.y==b.y?a.x<b.x:a.y<b.y;}
int y[310],N;
ll q1[310],q2[310],x[610];
int Q;
void merge(){
	int i,j;
	Q=0;
	for(i=j=1;i<=N||j<=N;)x[++Q]=(j>N||(i<=N&&q1[i]<q2[j])?q1[i++]:q2[j++]);
	Q=unique(x+1,x+Q+1)-x-1;
}
int a[310][310],b[310][310],c[310][310];
int ta[610],tb[610],tc[610];
struct dat{
	ll x;
	int y;
	dat(ll x=0,int y=0):x(x),y(y){}
};
struct queue{
	dat q[610];
	int l,r;
	void clear(){
		l=1;
		r=0;
	}
	void push(dat t){
		while(l<=r&&q[r].y<=t.y)r--;
		q[++r]=t;
	}
	void pop(ll x){
		while(l<=r&&q[l].x<=x)l++;
	}
	int top(){
		assert(l<=r);
		return q[l].y;
	}
}qa,qb,qc;
ll ans;
int minw;
void work(ll wi){
	int i,l,r;
	if(wi<minw)return;
	for(i=1;i<=N;i++){
		q1[i]=y[i];
		q2[i]=y[i]+wi+1;
	}
	merge();
	l=1;
	r=0;
	for(i=1;i<Q;i++){
		while(l<=n&&p[l].y+wi<x[i])l++;
		while(r+1<=n&&p[r+1].y<x[i+1])r++;
		assert(l<=r);
		ta[i]=a[l][r];
		tb[i]=b[l][r];
		tc[i]=c[l][r];
	}
	qa.clear();
	qb.clear();
	qc.clear();
	r=2;
	for(i=1;i<=n&&p[i].y+C<=x[Q];i++){
		while(r<=Q&&x[r-1]<p[i].y+C){
			qa.push(dat(x[r],ta[r-1]));
			qb.push(dat(x[r],tb[r-1]));
			qc.push(dat(x[r],tc[r-1]));
			r++;
		}
		qa.pop(p[i].y);
		qb.pop(p[i].y);
		qc.pop(p[i].y);
		ans=min(ans,wi+max(qa.top()+qb.top(),qc.top()));
	}
}
int q[310],t;
int w[150010],M;
int main(){
	int i,j,k,u;
	scanf("%d%d%d",&R,&C,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		y[i]=p[i].y;
	}
	sort(p+1,p+n+1);
	for(i=1;i<=n;i++){
		t=0;
		for(j=i;j<=n;j++){
			for(k=t;q[k]>p[j].x;k--)q[k+1]=q[k];
			q[k+1]=p[j].x;
			t++;
			a[i][j]=q[1]-1;
			b[i][j]=R-q[t];
			u=0;
			for(k=1;k<t;k++)u=max(u,q[k+1]-q[k]-1);
			c[i][j]=u;
		}
	}
	for(i=1;i<=n;i++){
		if(p[i].y!=y[N])y[++N]=p[i].y;
	}
	minw=y[1]-1+C-y[N];
	for(i=1;i<N;i++)minw=max(minw,y[i+1]-y[i]-1);
	for(i=1;i<N;i++){
		for(j=i+1;j<=N;j++){
			w[++M]=y[j]-y[i]-1;
			w[++M]=y[i]-1+C-y[j];
			w[++M]=y[j]-1+C-y[i];
		}
	}
	w[++M]=C-1;
	sort(w+1,w+M+1);
	M=unique(w+1,w+M+1)-w-1;
	ans=R+C-2;
	for(i=1;i<=M;i++)work(w[i]);
	printf("%lld\n",ans);
}
