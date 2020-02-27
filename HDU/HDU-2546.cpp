/*
 * HDU-2546
 * Hint: 01-knapsack
 * */
#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<algorithm>
using namespace std;

const int maxn = 1000+5;
int dp[maxn], cost[maxn];
int money, n;

void work(){
    for(int i=0; i<n-1; i++)
        for(int j=money-5; j>=cost[i]; j--)
            dp[j] = max(dp[j], dp[j-cost[i]]+cost[i]);
}

int main(){
    while(~scanf("%d", &n) && n){
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++)
            scanf("%d", &cost[i]);
        scanf("%d", &money);
        if(money<5)
            printf("%d\n", money);
        else{
            sort(cost, cost+n);
            work();
            printf("%d\n", money-dp[money-5]-cost[n-1]);
        }
    }
    return 0;
}
