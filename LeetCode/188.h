/*
    188. Best Time to Buy and Sell Stock IV
	Hint: DP
    Time: O(k*n)
    Space: O(k*n)
*/
class Solution {
 public:
	int maxProfit(int k, vector<int>& prices) {
		if(k == 0 || prices.size() <= 1)
			return 0;
		if(k >= prices.size() / 2)
			return getMaxProfit(prices);
		/*
            Buying a stock is equivalent to subtracting the price of that day.
            Selling a stock is equivalent to adding the price of that day.
            Suppose that you buy on day i and sell on day j, the profit 
            will be -prices[i] + prices[j].
            
            localMax means that the maximum profit until now with one 
            stock waiting to be sold.
            
            F[i][j] means that the maximum profit from day 0 to i 
            using j transaction.
            F[i][j] = max(F[i-1][j], prices[i] + localMax)
		*/
		int F[prices.size()+1][k+1], localMax;
		memset(F, 0, sizeof(F));
		for(int j=1; j<=k; j++){
			localMax = -prices[0];  // Buy on day 1 (the stock waiting to be sold)
			for(int i=1; i<prices.size(); i++){
				F[i][j] = max(F[i-1][j], prices[i] + localMax);
				localMax = max(localMax, F[i-1][j-1] - prices[i]);  // Buy on day i
			}//for
		}//for
		return F[prices.size()-1][k];
	}

	int getMaxProfit(vector<int>& prices){
		int ret = 0;
		for(int i=1; i<prices.size(); i++){
			if(prices[i] > prices[i-1])
				ret += (prices[i] - prices[i-1]);
		}//for
		return ret;
	}
};
