/*
 * The Knapsack problem
 * Hint: Dynamic programming
 * */
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn = 20+5;
int dp[maxn][maxn];
int v[maxn], s[maxn];

int knapsack(int n, int m){
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int j=0; j<=m; j++)
        dp[0][j] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = dp[i-1][j];
            if(s[i] <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j-s[i]]+v[i]);
        }
    }
    return dp[n][m];
}

int maim(){
	return 0;
}
