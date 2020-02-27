#include<stdio.h>

int n;
long long ans;
bool found;

void dfs(long long num, int step){
	if(found || step == 19)
		return;
	if(num % n == 0){
		printf("%lld\n", num);
		found = true;
	}
	dfs(num*10, step+1);
	dfs(num*10+1, step+1);
	return;
}

int main(){
	while(scanf("%d", &n) && n){
		found = false;
		dfs(1, 0);
	}
	return 0;
}
