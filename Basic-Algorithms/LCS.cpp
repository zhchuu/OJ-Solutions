/*
 * Longest common subsequence
 * Hint: Dynamic programming
 * */
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

const int maxl = 50+5;
int dp[maxl][maxl];
char a[maxl], b[maxl];

int lcs(int n, int m){
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int j=0; j<=m; j++)
        dp[0][j] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main(){
    //strcpy(a, " xyxxzxyzxy");
    //strcpy(b, " zxzyyzxxyxxz");
    printf("a: ");
    scanf("%s", a+1);
    printf("b: ");
    scanf("%s", b+1);
    //printf("%d %d\n", strlen(a+1), strlen(b+1));
    int ans = lcs(strlen(a+1), strlen(b+1));
    //printf("a: %s\n", a+1);
    //printf("b: %s\n", b+1);
    printf("lcs: %d\n", ans);
}
