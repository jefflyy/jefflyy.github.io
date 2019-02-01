#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
struct pnt{
	int x,y;
	pnt(int x=0,int y=0):x(x),y(y){}
}p[10],rb;
pnt operator+(pnt a,pnt b){return pnt(a.x+b.x,a.y+b.y);}
pnt&operator+=(pnt&a,pnt b){return a=a+b;}
pnt operator-(pnt a,pnt b){return pnt(a.x-b.x,a.y-b.y);}
bool operator==(pnt a,pnt b){return a.x==b.x&&a.y==b.y;}
bool operator!=(pnt a,pnt b){return a.x!=b.x||a.y!=b.y;}
bool operator<(pnt a,pnt b){return a.x==b.x?a.y<b.y:a.x<b.x;}
const pnt w[4]={pnt(0,1),pnt(0,-1),pnt(-1,0),pnt(1,0)};
const char*id="UDLR";
int rev(pnt w){
	for(int i=0;i<4;i++){
		if(w==::w[i])return i;
	}
	return-1;
}
set<pnt>s;
#define is(p) s.count(p)
void move(int i){
	putchar(id[i]);
	pnt w=::w[i];
	rb+=w;
	for(i=1;i<=5;i++){
		if(rb==p[i]){
			s.erase(p[i]);
			s.insert(p[i]+=w);
			return;
		}
	}
}
pnt q[100010];
int fa[100010],st[100010];
set<pnt>v;
void moveto(pnt en){
	int head,tail,i,tp;
	pnt x,y;
	v.clear();
	v.insert(q[head=tail=1]=rb);
	while(head<=tail){
		x=q[head];
		if(x==en)break;
		for(i=0;i<4;i++){
			y=x+w[i];
			if(!is(y)&&!v.count(y)){
				v.insert(q[++tail]=y);
				fa[tail]=head;
			}
		}
		head++;
	}
	tp=0;
	for(i=head;fa[i];i=fa[i])st[++tp]=rev(q[i]-q[fa[i]]);
	while(tp)move(st[tp--]);
}
void gao(pnt up){
	moveto(up+w[0]);
	move(1);
	up+=w[1];
	for(int i=1;i<=5;i++){
		if(p[i]!=up&&p[i]!=up+w[1]&&p[i]!=up+w[2]&&p[i]!=up+w[3]){
			if(p[i].x<up.x){
				moveto(p[i]+w[3]);
				while(rb.x>=up.x-1)move(2);
				moveto(rb+pnt(-1,1));
				while(rb.y>up.y-1)move(1);
				moveto(rb+pnt(-1,-1));
				while(rb.x<up.x-1)move(3);
				moveto(rb+pnt(1,-1));
			}else{
				moveto(p[i]+w[2]);
				while(rb.x<=up.x+1)move(3);
				moveto(rb+pnt(1,1));
				while(rb.y>up.y-1)move(1);
				moveto(rb+pnt(1,-1));
				while(rb.x>up.x+1)move(2);
				moveto(rb+pnt(-1,-1));
			}
			while(rb.y<up.y-2)move(0);
			return;
		}
	}
}
void move(int i,int x,int y){
	moveto(p[i]+w[2]);
	while(rb.x<x-1)move(3);
	moveto(rb+pnt(1,-1));
	while(rb.y<y-1)move(0);
}
int main(){
	int i;
	for(i=1;i<=5;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		s.insert(p[i]);
	}
	if(is(w[0])&&is(w[1])&&is(w[2])&&is(w[3])){
		for(i=1;i<=5;i++){
			if(p[i]!=w[0]&&p[i]!=w[1]&&p[i]!=w[2]&&p[i]!=w[3])move(p[i].x<0?3:2);
		}
	}
	for(i=1;i<=5;i++){
		if(is(p[i]+pnt(-1,-1))&&is(p[i]+pnt(0,-2))&&is(p[i]+pnt(1,-1))){
			gao(p[i]);
			return 0;
		}
	}
	sort(p+1,p+6);
	move(5,8,8);
	move(4,7,8);
	move(3,6,8);
	move(2,7,7);
	move(1,7,6);
}
