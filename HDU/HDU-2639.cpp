/*
 * HDU-2639
 * Complile: G++
 */
#include<bits/stdc++.h>

using namespace std;

const int maxn = 100+5;
const int maxv = 1000+5;
const int maxk = 30+2;

int T, N, V, K;
int value[maxn];
int volumn[maxn];

int main(){
    scanf("%d", &T);
    while(T--){
	scanf("%d %d %d", &N, &V, &K);
	int dp[maxv][maxk]; // dp[v][k] means the k-th maximum in value v
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<N; i++)
	    scanf("%d", &value[i]);
	for(int i=0; i<N; i++)
	    scanf("%d", &volumn[i]);

	for(int i=0; i<N; i++){
	    for(int j=V; j>=volumn[i]; j--){
		int a[2*maxk]; // save both dp[i][k] and dp[i-volumn][k] + value, therefore double the size
		memset(a, 0, sizeof(a));
		int cnt = 0;
		for(int k=0; k<K; k++){
		    // store both of them because we are finding k-th but we don't know which one is until they are sorted
		    a[cnt++] = dp[j][k];
		    a[cnt++] = dp[j-volumn[i]][k] + value[i];
		}//for

		sort(a, a+cnt, greater<int>());
		int* cnt2 = unique(a, a+cnt);
		while(cnt2 != a+cnt){ // assign others with zeros
		    *cnt2 = 0;
		    cnt2++;
		}
		copy(a, a+K, dp[j]);
	    }//for
	}//for
	printf("%d\n", dp[V][K-1]);
    }//while
    
    return 0;
}
