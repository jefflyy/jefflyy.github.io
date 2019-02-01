#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<algorithm>
using namespace std;
typedef long double du;
const du eps=1e-6;
du sqr(du x){return x*x;}
int n;
du x[20][20],r[20];
du a[20][20];
du ta[20],tb[20];
void gauss(){
	int i,j,k;
	du t;
	for(i=1;i<=n;i++){
		if(!a[i][i]){
			for(j=i+1;j<=n;j++){
				if(a[j][i])break;
			}
			for(k=i;k<=n+2;k++)swap(a[i][k],a[j][k]);
		}
		for(j=i+1;j<=n;j++){
			t=a[j][i]/a[i][i];
			for(k=i;k<=n+2;k++)a[j][k]-=a[i][k]*t;
		}
	}
	for(i=n;i>0;i--){
		ta[i]=a[i][n+1];
		tb[i]=a[i][n+2];
		for(j=n;j>i;j--){
			ta[i]-=ta[j]*a[i][j];
			tb[i]-=tb[j]*a[i][j];
		}
		ta[i]/=a[i][i];
		tb[i]/=a[i][i];
	}
}
bool solve(du a,du b,du c,du&x1,du&x2){
	assert(a);
	du d=b*b-4*a*c;
	if(d<-eps)return 0;
	d=sqrtl(max(d,0.l));
	x1=(-b+d)/(2*a);
	x2=(-b-d)/(2*a);
	return 1;
}
struct ans{
	du x[20][20];
}p[2510];
bool sneq(const du*a,const du*b){
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i])return 1;
	}
	return 0;
}
bool slt(const du*a,const du*b){
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i])return a[i]<b[i];
	}
	return 0;
}
bool operator<(const ans&a,const ans&b){
	for(int i=1;i<=n;i++){
		if(sneq(a.x[i],b.x[i]))return slt(a.x[i],b.x[i]);
	}
	return 0;
}
bool neq(const du*a,const du*b){
	for(int i=1;i<=n;i++){
		if(fabsl(a[i]-b[i])>eps)return 1;
	}
	return 0;
}
bool operator==(const ans&a,const ans&b){
	for(int i=1;i<=n;i++){
		if(neq(a.x[i],b.x[i]))return 0;
	}
	return 1;
}
int M;
namespace line{
	du a[20],b;
	ans t;
	void getints(){
		du sa,sb,lm;
		int i,j;
		for(i=1;i<=n;i++){
			sa=sb=0;
			for(j=1;j<=n;j++){
				sa+=sqr(a[j]);
				sb+=a[j]*x[i][j];
			}
			sb+=b;
			lm=-sb/sa;
			for(j=1;j<=n;j++)t.x[i][j]=x[i][j]+lm*a[j];
		}
		p[++M]=t;
	}
	void gao(du x){
		int i;
		b=x;
		for(i=1;i<=n;i++)a[i]=ta[i]*x+tb[i];
		getints();
	}
}
const du dt[]={0,.124222,.7543,.44423432,.6431,.222908,.3907,.114514,.0604,.5159,.81022215};
void work(){
	int i,j,k;
	du sa,sb,sc,x1,x2;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%Lf",x[i]+j);
			x[i][j]-=dt[j];
		}
		scanf("%Lf",r+i);
	}
	M=0;
	for(i=0;i<1<<n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++)a[j][k]=x[j][k];
			a[j][n+1]=-1;
			a[j][n+2]=i>>(j-1)&1?r[j]:-r[j];
		}
		gauss();
		sa=sb=sc=0;
		for(j=1;j<=n;j++){
			sa+=sqr(ta[j]);
			sb+=2*ta[j]*tb[j];
			sc+=sqr(tb[j]);
		}
		sc--;
		if(solve(sa,sb,sc,x1,x2)){
			line::gao(x1);
			line::gao(x2);
		}
	}
	sort(p+1,p+M+1);
	M=unique(p+1,p+M+1)-p-1;
	printf("%d\n",M);
	for(i=1;i<=M;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++)printf("%.20Lf%c",p[i].x[j][k]+dt[k]," \n"[k==n]);
		}
	}
	putchar('\n');
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)work();
}
//2.out is wrong