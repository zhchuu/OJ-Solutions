/*
 * dp[i][j] means that split arr[1...j] into i section.
 * dp[i][j] = max(dp[i][j-1] + arr[j], max(dp[i-1][k]) + arr[j]) (0<k<j)
 * use dp[j-1] instead of dp[i][j-1], use Max[j-1] instead of max(dp[i-1][k])
 */
#include<stdio.h>
#include<memory.h>
#define max(a, b) (a < b ? b : a)
#define INF 0x7fffffff

const int maxn = 1000000 + 5;
int s[maxn];
int dp[maxn], Max[maxn];

int main(){
    int n, m, ans;
    while(~scanf("%d %d", &m, &n)){
	for(int i=1; i<=n; i++)
	    scanf("%d", &s[i]);
	memset(dp, 0, sizeof(dp));
	memset(Max, 0, sizeof(Max));
	for(int i=1; i<=m; i++){
	    ans = -INF;
	    for(int j=i; j<=n; j++){
		dp[j] = max(dp[j-1] + s[j], Max[j-1] + s[j]);
		Max[j-1] = ans;
		ans = max(ans, dp[j]);
	    }
	}
	printf("%d\n", ans);
    }//while
    return 0;
}
