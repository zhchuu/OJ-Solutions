/*
 * HDU-2845
 * Hint: dp, maximum discontinuous subsequence
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn = 200000+5;
int row[maxn], col[maxn], M, N, dp[maxn];

int main(){
    while(~scanf("%d %d", &M, &N)){
        for(int i=1; i<=M; i++){
            for(int j=1; j<=N; j++)//input row
                scanf("%d", &row[j]);
            dp[0] = 0;
            dp[1] = row[1];
            for(int k=2; k<=N; k++)
                dp[k] = max(dp[k-2] + row[k], dp[k-1]);
            col[i] = dp[N];
        }
        dp[0] = 0;
        dp[1] = col[1];
        for(int k=2; k<=M; k++)
            dp[k] = max(dp[k-2] + col[k], dp[k-1]);
        printf("%d\n", dp[M]);
    }//while
    return 0;
}
