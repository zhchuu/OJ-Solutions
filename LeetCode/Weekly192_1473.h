/*
    1473. Paint House III
*/
class Solution {
public:
    int dp[100][21][101];
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0, houses, cost, m, n, target);
        if(ans < INT_MAX/2)
            return ans;
        return -1;
    }

    int solve(int i, int j, int k, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        if(k > target)
            return INT_MAX / 2;
        if(i == m){
            if(k == target)
                return 0;
            else
                return INT_MAX / 2;
        }//if
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        int ans = INT_MAX / 2;
        if(houses[i] != 0)
            ans = min(ans, solve(i+1, houses[i], k+(houses[i] != j), houses, cost, m, n, target));
        else{
            for(int c=0; c<n; c++){
                ans = min(ans, cost[i][c] + solve(i+1, c+1, k+(c+1 != j), houses, cost, m, n, target));
            }//for
        }//if-else

        return dp[i][j][k] = ans;
    }

};
