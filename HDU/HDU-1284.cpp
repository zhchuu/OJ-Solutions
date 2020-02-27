/*
 * HDU-1284
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 32768+2;
int dp[maxn], n;

int main(){
    int coins[3] = {1, 2, 3};
    while(~scanf("%d", &n)){
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i=0; i<3; i++)
        for(int j=coins[i]; j<=n; j++)
            dp[j] += dp[j-coins[i]];
        printf("%d\n",dp[n]);
    }
    return 0;
}
