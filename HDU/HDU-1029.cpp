/*
 * hdu1029 Ignatius and the Princess IV
 * Hint: Elemate number pair
 * Format: gcc
 * */

#include<stdio.h>
#include<memory.h>
const int maxN = 1000000;
int N;
int A[maxN];
int candidate(int arr[], int pos, int last){
	int c = arr[pos], cnt = 1, i;
	if(pos == last)
		return c;
	for(i=pos+1; i<=last && cnt>0; i++){
		if(arr[i] == c)
			cnt++;
		else
			cnt--;
	}//for
	if(i == last+1)
		return c;
	else
		return candidate(arr, i, last);
}
int main(){
	while(~scanf("%d",&N)){
		memset(A, -1, sizeof(A));
		for(int k =1;k<=N;k++)
			scanf("%d",&A[k]);
		int ans = candidate(A, 1, N);
		printf("%d\n", ans);
	}//while
	return 0;
}
