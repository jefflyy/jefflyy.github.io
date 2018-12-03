#include<stdio.h>
#include<windows.h>
const char*name="usmjeri";
char s[110];
int main(){
	int i,j,m;
	for(i=1;i<=10;i++){
		if(i<=2){
			sprintf(s,"ren %s.out.%d %s%d.out",name,i,name,i);
			puts(s);
			system(s);
		}else{
			m=i<=6?2:3;
			for(j=0;j<m;j++){
				sprintf(s,"ren %s.out.%d%c %s%d%c.out",name,i,'a'+j,name,i,'a'+j);
				puts(s);
				system(s);
			}
		}
	}
}
