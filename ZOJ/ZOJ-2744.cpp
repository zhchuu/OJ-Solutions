/*
 * ZOJ-2744
 * Hint: dp
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxl = 5000+5;
bool dp[maxl][maxl];//dp[i][j] shows that if it's palindrome from i to j
char str[maxl];

int work(){
    int len = strlen(str), ret = 0;
    memset(dp, 0, sizeof(dp));
    for(int k=0; k<len; k++){
        dp[k][k] = 1;
        ret += 1;
    }
    for(int i=len-1; i>=0; i--)//must from len-1 to 0
    for(int j=i+1; j<len; j++){
        if(str[i] == str[j] && (i+1 >= j-1 || dp[i+1][j-1])){
            dp[i][j] = 1;
            ret += 1;
        }
    }//for
    return ret;
}

int main(){
    while(scanf("%s", str) != EOF){
        int ans = work();
        printf("%d\n", ans);
    }
    return 0;
}
