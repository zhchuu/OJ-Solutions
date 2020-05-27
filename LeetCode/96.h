/*
    96. Unique Binary Search Trees
    Time: O(n!)
    Space: O(n)
*/
class Solution {
public:
    int dp[1000];
    int numTrees(int n) {
        /*
            DP
            dp[i] represents the number of UBST if i
            dp[i] = 2*dp[i-1] + dp[j-1]*dp[i-j] for j in [2, i-1]
        */
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        return getNum(n);
    }

    int getNum(int n){
        if(dp[n] != 0)
            return dp[n];
        int ret = 2*getNum(n-1);
        for(int i=2; i<=n-1; i++){
            ret += getNum(i-1)*getNum(n-i);
        }//for
        return ret;
    }
};
