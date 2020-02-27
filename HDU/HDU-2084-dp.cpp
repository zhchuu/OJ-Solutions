/*
 * HDU-2084
 * Hint: dp
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 100+5;
int dp[maxn][maxn];//dp[i][j] means the maximum of row i column j
int num[maxn][maxn], n;
//dp[i][j] = max(dp[i-1][j],  dp[i-1][j-1]) + num[i][j]

void init(){
    memset(dp, 0, sizeof(dp));
    memset(num, 0, sizeof(num));
}

int work(){
    for(int i=1; i<=n; i++)
    for(int j=1; j<=i; j++)
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + num[i][j];
    int ret = -1;
    for(int i=1; i<=n; i++)
        ret = max(ret, dp[n][i]);
    return ret;
}

int main(){
    int kase;
    scanf("%d", &kase);
    while(kase--){
        init();
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            scanf("%d", &num[i][j]);
        int ans = work();
        printf("%d\n", ans);
    }
    return 0;
}
