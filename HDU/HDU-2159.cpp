/*
 * HDU-2159
 * Hint: two-demension knapsack
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int INF = 1000000;
const int maxk = 100+5;
int dp[maxk][maxk], n, m, k, s, ex[maxk], tol[maxk];//killing i monster with j tolerance, you get maximum exp dp[i][j]

int main(){
    while(~scanf("%d %d %d %d", &n, &m, &k, &s)){
        for(int i=1; i<=k; i++)
            scanf("%d %d", &ex[i], &tol[i]);
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=k;i++)
        for(int l=1; l<=s; l++)
        for(int j=tol[i]; j<=m; j++ )
            dp[l][j] = max(dp[l][j], dp[l-1][j-tol[i]] + ex[i]);
        int q;
        for(q=0; q<=m; q++)
        if(dp[s][q] >= n)
            break;
        if(dp[s][q] < n)
            printf("-1\n");
        else
            printf("%d\n", m - q);
    }
    return 0;
}
