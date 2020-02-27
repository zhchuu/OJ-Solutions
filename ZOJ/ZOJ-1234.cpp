/*
 * ZOJ-1234
 * Hint: dp
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn = 1000+20;
int dp[maxn*5][maxn];//dp[i][j] means the minmum badness of j sets in L[i...N].
int L[maxn*5];//amount of chopsticks
int K, N;

int square(int a){
    return a*a;
}

int work(){
    memset(dp, 0, sizeof(dp));
    dp[N-1][1] = square(L[N-1] - L[N]);
    for(int i=N-2; i>=1; i--)
    for(int j=1; j<=K; j++){
        if(N-i+1 < 3*j)
            break;
        if(N-i+1 == 3*j)
            dp[i][j] = dp[i+2][j-1] + square(L[i] - L[i+1]);
        else
            dp[i][j] = min(dp[i+1][j], dp[i+2][j-1] + square(L[i] - L[i+1]));
    }
    return dp[1][K];
}

int main(){
    int kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d%d", &K, &N);
        K += 8;
        for(int i=1; i<=N; i++)
            scanf("%d", &L[i]);
        int ans = work();
        printf("%d\n", ans);
    }
    return 0;
}
