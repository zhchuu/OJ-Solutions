/*
 * HDU-2018
 * Hint: dp
 * */
#include<stdio.h>
#include<memory.h>
using namespace std;

const int maxn = 55+5;
int dp[maxn], n;

int get(int m){
    if(dp[m] != 0)
        return dp[m];
    return (get(m-1) + get(m-3));
}

int main(){
    memset(dp, 0, sizeof(dp));
    dp[1] = 1; dp[2] = 2; dp[3] = 3;
    while(~scanf("%d", &n) && n){
        int ans = get(n);
        printf("%d\n", ans);
    }
    return 0;
}
