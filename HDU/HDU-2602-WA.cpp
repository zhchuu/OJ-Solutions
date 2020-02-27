/*
 * HDU-2602
 * Hint: dp, knapsack
 * WA. Because the space maybe 0.
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn = 1000+5;
int dp[maxn][maxn];//dp[i][j] indicates that the maximum of collecting first i items into a backpack with a capacity of j
int n, v, value[maxn], space[maxn];

void init(){
    memset(dp, 0, sizeof(dp));
}

void work(){
    for(int i=1; i<=n; i++)
    for(int j=v; j>=space[i]; j--){
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-space[i]] + value[i]);
        //printf("output: %d %d %d\n", i, j, dp[i][j]);
    }
}

int main(){
    int kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d %d", &n, &v);
        for(int i=1; i<=n; i++)
            scanf("%d", &value[i]);
        for(int i=1; i<=n; i++)
            scanf("%d", &space[i]);
        init();
        work();
        printf("%d\n", dp[n][v]);
    }
    return 0;
}
