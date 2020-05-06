/*
    309. Best Time to Buy and Sell Stock with Cooldown
    Hint: DP
    Time: O(n)
    Space: O(n)
*/
class Solution {
 public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() <= 1)
			return 0;
		/*
            F[i] means that the maximum profit with cooldown.
            You can buy day i+1 now.
            
            localMax means that the maximun profit until now
            with one stock waiting to be sold.
		*/
		int F[prices.size()+2], localMax = -prices[0];  // Day 0 waiting to be sold
		memset(F, 0, sizeof(F));
		for(int i=2; i<prices.size()+1; i++){
			F[i] = max(F[i-1], prices[i-1] + localMax);  // Sell on day i-1, cooldown on day i
			localMax = max(localMax, F[i-2] - prices[i-1]);  // Buy on day i-1
		}//for
		return F[prices.size()];
	}
};
