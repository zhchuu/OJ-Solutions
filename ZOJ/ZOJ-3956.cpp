/*
 * ZOJ-3956
 * Hint: 01-knapsack
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxc = 50000+5;
const int maxn = 5000+5;
const long long INF = 1e15;
long long dp[maxc], h[maxn], c[maxn];
int n;

int main(){
    int kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%lld %lld", &h[i], &c[i]);
        //init
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<maxc; i++)
            dp[i] = -INF;
        for(int i=0; i<n; i++)
        for(int j=maxc; j>=c[i]; j--)
            dp[j] = max(dp[j], dp[j-c[i]] + h[i]);
        long long ans = 0;
        for(int i=0; i<maxc; i++)
        if(dp[i] > 0)
            ans = max(ans, dp[i]*dp[i] - dp[i]*i - i*i);
        printf("%lld\n", ans);
    }
    return 0;
}
