#include<stdio.h>
#include<windows.h>
char s[110];
int main(){
	int i,j;
	for(i=1;i<=4;i++){
		for(j='a';j<='c';j++){
			sprintf(s,"ren garaza.out.%d%c garaza%d%c.out",i,j,i,j);
			system(s);
		}
	}
}
