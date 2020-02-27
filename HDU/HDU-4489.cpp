/*
 * HDU-4489
 * Hint: dp
 */
#include<stdio.h>

typedef long long ll;
const int maxn = 20+2;
ll dp[30][2];
ll ans[30];
ll c[30][30];

void init(){
    c[1][1] = 1;
    for(int i=1; i<=maxn; i++)
	c[i][0] = 1;
    for(int i=2; i<=maxn; i++)
    for(int j=1; j<=i; j++)
	c[i][j] = c[i-1][j] + c[i-1][j-1];
}

int main(){
    init();
    dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 1;
    for(int i=2; i<=30; i++){
	ans[i] = 0;
	for(int j=0; j<=i-1; j++)
	    ans[i] += c[i-1][j]*dp[j][0]*dp[i-1-j][1];
	dp[i][0] = dp[i][1] = ans[i]/2;
    }
    ans[1] = 1;
    
    int kase, d, n;
    scanf("%d", &kase);
    for(int i=1; i<=kase; i++){
	scanf("%d %d", &d, &n);
	printf("%d %lld\n", d, ans[n]);
    }//for
    return 0;
}
