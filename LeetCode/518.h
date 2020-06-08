/*
    518. Coin Change 2
    Top-down DP
*/
class Solution {
public:
    int dp[500+5][5000+5];
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(coins, 0, amount);
    }

    int solve(vector<int>& coins, int i, int amount){
        if(amount == 0) return 1;
        if(amount < 0 || i == coins.size()) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        return dp[i][amount] = solve(coins, i, amount-coins[i]) + solve(coins, i+1, amount);
    }
};
