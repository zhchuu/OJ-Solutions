/*
 * HDU-2571
 * Hint: dp
 * */
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

#define INF 99999;
const int maxm = 1000+5;
const int maxn = 20+5;
int dp[maxn][maxm];
int maze[maxn][maxm], n, m;

void init(){
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            dp[i][j] = -INF;
}

void work(){
    dp[1][1] = maze[1][1];
    for(int i=1; i<=n; i++){
        for(int j=1;j<=m; j++){
            for(int k=1;k<j;k++){
                if(j%k == 0)
                    dp[i][j] = max(dp[i][j], dp[i][k] + maze[i][j]);
		    }
            dp[i][j] = max(dp[i][j], dp[i][j-1] + maze[i][j]);
            dp[i][j] = max(dp[i][j], dp[i-1][j] + maze[i][j]);
	    }
    }
}

int main(){
    int kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                scanf("%d", &maze[i][j]);
        init();
        work();
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
