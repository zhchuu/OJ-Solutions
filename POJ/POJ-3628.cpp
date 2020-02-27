/*
 * POJ-3628
 * Hint: dp, dfs
 */
#include<stdio.h>
#define max(a, b) (a < b ? b : a)
const int maxn = 20000000+5;
const int INF = 0x3f3f3f3f;
int n, b, sum=0;
int h[20+2];
int dp[maxn];

int main(){
    scanf("%d %d", &n, &b);
    for(int i=1; i<=n; i++){
	scanf("%d", &h[i]);
	sum += h[i];
    }

    // memset
    for(int i=0; i<=sum; i++)
	dp[i] = 0;

    for(int i=1; i<=n; i++)
	for(int v=sum; v>=h[i]; v--)
	    dp[v] = max(dp[v], dp[v-h[i]] + h[i]);

    int ans = INF;
    for(int i=b; i<=sum; i++)
	if(dp[i]>=b && dp[i] - b < ans)
	    ans = dp[i] - b;

    printf("%d\n", ans);

    return 0;
}
