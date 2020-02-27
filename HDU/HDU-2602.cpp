/*
 * HDU-2602
 * Hint: dp, knapsack
 * 0-1 knapsack's loop: 1~i~N and V~j~s[i] for keeping every item being used once
 * unlimited knapsack's loop: 1~i~N and 0~j~V for keeping backtracking effective
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn = 1000+5;
int dp[maxn];//dp[i] indicates that the maximum under capacity of j
int n, v, value[maxn], space[maxn];

void init(){
    memset(dp, 0, sizeof(dp));
}

void work(){
    for(int i=1; i<=n; i++)
        for(int j=v; j>=space[i]; j--)
            dp[j] = max(dp[j], dp[j-space[i]] + value[i]);
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
        printf("%d\n", dp[v]);
    }
    return 0;
}
