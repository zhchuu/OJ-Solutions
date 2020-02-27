/*
 * HDU-2044
 * Hint: dp
 * */
#include<stdio.h>
#include<memory.h>

const int maxn = 50+5;
long long dp[maxn];//use long long

void initialize(){
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for(int i=3; i<maxn; i++)
        dp[i] = dp[i-1] + dp[i-2];
}

int main(){
    initialize();
    int kase, a, b;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d%d", &a, &b);
        printf("%I64d\n", dp[b-a]);
        //printf("%lld\n", dp[b-a]);
    }
    return 0;
}
