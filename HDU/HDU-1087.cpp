/*
 * HDU-1087
 * Hint: dp
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn = 1000+5;
int dp[maxn], num[maxn], N;

int work(){
    int ret = 0;
    dp[0] = num[0];
    for(int i=1; i<N; i++){
        dp[i] = num[i];
        for(int j=0; j<i; j++){
            if(num[j] >= num[i])
                continue;
            dp[i] = max(dp[j] + num[i], dp[i]);
        }
        ret = max(ret, dp[i]);
    }
    return ret;
}

int main(){
    while(~scanf("%d", &N) && N){
        for(int i=0; i<N; i++)
            scanf("%d", &num[i]);
        int ans = work();
        printf("%d\n", ans);
    }
    return 0;
}
