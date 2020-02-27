/*
 * HDU-2126
 * Hint: 01-knapsack, recording
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxm = 500+5;
int dp[maxm][2], n, m, price[maxm];

int main(){
    int kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++)
            scanf("%d", &price[i]);
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<=m; i++)
            dp[i][1] = 1;
        for(int i=0; i<n; i++)
        for(int j=m; j>=price[i]; j--){
            if(dp[j][0] < dp[j-price[i]][0] + 1){
                dp[j][0] = dp[j-price[i]][0] + 1;
                dp[j][1] = dp[j-price[i]][1];
            }else if(dp[j][0] == dp[j-price[i]][0] +1)
                dp[j][1] += dp[j-price[i]][1];
        }
        if(dp[m][0])
            printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n", dp[m][1], dp[m][0]);
        else
            printf("Sorry, you can't buy anything.\n");
    }
    return 0;
}
