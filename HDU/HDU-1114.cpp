/*
 * HDU-1114
 * Hint: knapsack
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int INF = 1000000;
const int maxf = 10000+5;
const int maxn = 500+5;
int dp[maxf], E, F, v[maxn], c[maxn], n;

int main(){
    int kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d %d", &E, &F);
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            scanf("%d %d", &v[i], &c[i]);
        for(int i=1; i<maxf; i++)
            dp[i] = INF;
        dp[0] = 0;
        for(int i=1; i<=n; i++)
            for(int j=c[i]; j<=F-E; j++)
                dp[j] = min(dp[j], dp[j-c[i]] + v[i]);
        if(dp[F-E] >= INF)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[F-E]);
    }
    return 0;
}
