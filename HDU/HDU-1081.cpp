/*
 * HDU-1081
 * Hint: two-demension matrix to one-demension array, dp
 * Similar problems: ZOJ-1449, ZOJ-1074
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;
int dp[maxn][maxn], ans, N;//dp[i][j] = matrix[0][j] + matirx[1][j] + ... + matrix[i][j]

void work(){
    ans = -999999;
    int most;//maximum sum in previous column
    for(int i=1; i<=N; i++){
        for(int j=0; j<i; j++){//j must start from 0
            most = dp[i][1] - dp[j][1];
            for(int k=2; k<=N; k++){
                most = max(dp[i][k] - dp[j][k], most + dp[i][k] - dp[j][k]);
                ans = max(most, ans);
            }//loop k = 2 ~ N
        }//loop j = 0 ~ i-1
    }//loop i = 1 ~ N
}

int main(){
    while(~scanf("%d", &N)){
        memset(dp, 0, sizeof(dp));
        int tmp;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                scanf("%d", &tmp);
                dp[i][j] = dp[i-1][j] + tmp;
            }
        }
        work();
        printf("%d\n", ans);
    }//while
    return 0;
}
