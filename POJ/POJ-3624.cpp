/*
 * POJ-3624
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 12880+5;
int dp[maxn], value[3405], cost[3405], N, M;

int main(){
    while(~scanf("%d %d", &N, &M)){
        for(int i=1; i<=N; i++)
            scanf("%d %d", &cost[i], &value[i]);
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=N; i++)
            for(int j=M; j>=cost[i]; j--)
                dp[j] = max(dp[j], dp[j-cost[i]] + value[i]);
        printf("%d\n", dp[M]);
    }
    return 0;
}
