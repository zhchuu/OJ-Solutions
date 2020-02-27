/*
 * HDU-1176
 * Hint: dp
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 100000+5;
int dp[maxn][12], maxT, n;//dp[i][j] means the maximum from i second to the end in j position
                          //dp[i-1][j] += max(dp[i][j-1], dp[i][j], dp[i][j+1])

int maxOfThree(int a, int b, int c){
    return max(a, max(b, c));
}

void work(){
    for(int i=maxT; i>=1; i--)
        for(int j=1; j<=11; j++)
            dp[i-1][j] += maxOfThree(dp[i][j-1], dp[i][j], dp[i][j+1]);
}

int main(){
    int x, t;
    while(~scanf("%d", &n) && n){
        memset(dp, 0, sizeof(dp));
        maxT = 0;
        while(n--){
            scanf("%d%d", &x, &t);
            dp[t][x+1] += 1;
            maxT = max(maxT, t);
        }
        work();
        printf("%d\n", dp[0][6]);
    }
    return 0;
}
