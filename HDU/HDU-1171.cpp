/*
 * HDU-1171
 * Hint: dp, knapsack
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn = 2500+5;
int value[50+5], amount[50+5], dp[maxn], N, M;

void init(){

}

void work(){
    dp[0] = 0;
    for(int i=1; i<=N; i++){
        dp[i] = value[i];
        int idx = -1;
        for(int j=1; j<i; j++){
            if(amount[i] <= 0)
                continue;
            if(dp[j] + value[i] > dp[i]){
                dp[i] = dp[j] + value[i];
                idx = j;
            }//if
        }//for
        if(idx != -1)
            amount[idx] -= 1;
    }//for
}

int main(){

}
