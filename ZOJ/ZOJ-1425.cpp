/*
 * ZOJ-1425
 * Hint: LCS, dp
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

const int maxn = 100+5;
int a[maxn], b[maxn], lenA, lenB;
int dp[maxn][maxn];

void init(){
    memset(dp, 0, sizeof(dp));
}

void work(){
    for(int i=1; i<=lenA; i++){
        for(int j=1; j<=lenB; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i] != b[j]){
                int pos1, pos2;
                for(pos1 = i-1; pos1>=1; pos1--)
                    if(a[pos1] == b[j]) break;
                for(pos2 = j-1; pos2>=1; pos2--)
                    if(b[pos2] == a[i]) break;
                if(pos1 && pos2)
                    dp[i][j] = max(dp[i][j], dp[pos1-1][pos2-1] + 2);
            }//if
        }//for
    }//for
}

int main(){
    int kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d %d", &lenA, &lenB);
        for(int i=1; i<=lenA; i++)
            scanf("%d", &a[i]);
        for(int i=1; i<=lenB; i++)
            scanf("%d", &b[i]);
        init();
        work();
        printf("%d\n", dp[lenA][lenB]);
    }
    return 0;
}
