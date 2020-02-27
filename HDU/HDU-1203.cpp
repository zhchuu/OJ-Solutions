/*
 * HDU-1203
 * Hint: knapsack
 * */
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<memory.h>
using namespace std;

const int maxn = 10000+5;
int n, m, money[maxn];
double posi[maxn], dp[maxn];

void init(){
    for(int i=0; i<=n; i++)
        dp[i] = 1;
}

double work(){
    for(int i=0; i<m; i++)
    for(int j=n; j>=money[i]; j--)
        dp[j] = min(dp[j], dp[j-money[i]]*(1-posi[i]));
    return dp[n];
}

int main(){
    while(~scanf("%d %d", &n, &m) && (n || m)){//n may be zero
        for(int i=0; i<m; i++)
            scanf("%d %lf", &money[i], &posi[i]);
        init();
        double ans = (1 - work());
        printf("%.1lf%%\n", ans*100);
    }
    return 0;
}
