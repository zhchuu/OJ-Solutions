/*
    322. Coin Change
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for(int i=0; i<=amount; i++)
            dp[i] = INT_MAX / 2;
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(coins[j] <= i)
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }//for
        }//for
        if(dp[amount] == INT_MAX / 2)
            return -1;
        return dp[amount];
    }
};
