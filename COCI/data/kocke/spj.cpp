#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[10010];
struct pnt{
	int x,y;
	pnt(int x=0,int y=0):x(x),y(y){}
}p[10],rb;
pnt operator+(pnt a,pnt b){return pnt(a.x+b.x,a.y+b.y);}
void operator+=(pnt&a,pnt b){a=a+b;}
bool operator==(pnt a,pnt b){return a.x==b.x&&a.y==b.y;}
bool adj(pnt a,pnt b){return abs(a.x-b.x)+abs(a.y-b.y)==1;}
bool operator<(pnt a,pnt b){return a.y==b.y?a.x<b.x:a.y<b.y;}
pnt way(char c){
	if(c=='U')return pnt(0,1);
	if(c=='D')return pnt(0,-1);
	if(c=='L')return pnt(-1,0);
	if(c=='R')return pnt(1,0);
	throw 1;
	return 0;
}
int fa[10];
int get(int x){return fa[x]==x?x:(fa[x]=get(fa[x]));}
void move(char c){
	int i,j,x;
	bool flag;
	pnt w=way(c);
	flag=0;
	for(i=1;i<=5;i++){
		if(rb+w==p[i]){
			x=get(i);
			flag=1;
			break;
		}
	}
	if(flag){
		for(i=1;i<=5;i++){
			if(get(i)==x)p[i]+=w;
		}
		for(i=1;i<=5;i++)fa[i]=i;
		for(i=1;i<=5;i++){
			for(j=1;j<=5;j++){
				if(adj(p[i],p[j]))fa[get(i)]=get(j);
			}
		}
	}
	rb+=w;
}
bool checkt(){
	sort(p+1,p+6);
	return p[1].y+1==p[2].y&&p[2].y+1==p[3].y&&p[3].y==p[4].y&&p[4].y==p[5].y
		 &&p[1].x==p[2].x&&p[2].x==p[4].x&&p[3].x+1==p[4].x&&p[4].x+1==p[5].x;
}
int main(int argc,char**args){
	FILE*in,*out,*res,*rep;
	int n,i;
	in=fopen(args[1],"r");
	out=fopen(args[2],"r");
	res=fopen(args[5],"w");
	rep=fopen(args[6],"w");
	for(i=1;i<=5;i++)fscanf(in,"%d%d",&p[i].x,&p[i].y);
	for(i=1;i<=5;i++)fa[i]=i;
	fread(s,1,9999,out);
	n=strlen(s);
	try{
		for(i=0;i<n;i++)move(s[i]);
	}catch(int e){
		fprintf(res,"0");
		fprintf(rep,"invalid!");
		return 0;
	}
	fprintf(res,"%s",checkt()?args[4]:"0");
	fprintf(rep,"final position: ");
	for(i=1;i<=5;i++)fprintf(rep,"(%d,%d)%s",p[i].x,p[i].y,i<5?", ":" ");
	return 0;
}
