/*
 * HDU-2955
 * Hint: dp
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 10000+5;
int money[maxn], N, most; 
float posi[maxn], dp[maxn], P;

void work(){
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=1; i<=N; i++)
        for(int j=most; j>=money[i]; j--)
            dp[j] = max(dp[j], dp[j-money[i]]*posi[i]);
}

int main(){
    int kase;
    scanf("%d", &kase);
    while(kase--){
        most = 0;
        scanf("%f%d", &P, &N);
        P = 1 - P;
        for(int i=1; i<=N; i++){
            scanf("%d%f", &money[i], &posi[i]);
            most += money[i];
            posi[i] = 1 - posi[i];
        }//for
        work();
        int ans;
        for(ans=most; ans>=0; ans--)
            if(dp[ans] >= P)
                break;
        printf("%d\n", ans);
    }//while
    return 0;
}
