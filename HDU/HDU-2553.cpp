/*
 * hdu2553 N-queens
 * Hint: dfs, high time-limit required 
 * Format: gcc
 * */

#include<stdio.h>
#include<memory.h>
#include<math.h>
const int maxN = 10 + 2;
int N;
int table[maxN], idx, ans[maxN];
bool canPlace(int t[], int pos){
	//column conflict and diagonal conflict
	for(int i=1;i<pos;i++){
		if(t[i]==t[pos] || abs(pos-i) == abs(t[pos]-t[i]))
			return false;
	}
	return true;
}
int dfs(int n){
	idx = 1;
	int ret = 0;
	memset(table,0,sizeof(table));
	while(idx >= 1){
		table[idx]++;
		while(table[idx]<=n && !canPlace(table, idx))
			table[idx]++;
		if(table[idx] > n){
			table[idx] = 0;
			idx--;
		}else{
			if(idx == n)
				ret++;
			else
				idx++;
		}
	}//while
	return ret;
}
int main(){
	for(int i=1;i<=10;i++)//get all results
		ans[i] = dfs(i);	
	while(~scanf("%d",&N)&&N){	
		printf("%d\n",ans[N]);
	}
	return 0;
}
