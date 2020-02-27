/*
 * PAT L1-037
 * */

#include<stdio.h>

int main(){
	int a, b;
	scanf("%d %d", &a,&b);
	if(b == 0)
		printf("%d/0=Error", a);
	else if(b > 0)
		printf("%d/%d=%.2f",a,b,double(a)/double(b));
	else 
		printf("%d/(%d)=%.2f",a,b,double(a)/double(b));
	return 0;
}
