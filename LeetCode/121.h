/*
  121. Best Time to Buy and Sell Stock
*/
class Solution {
 public:
	int maxProfit(vector<int>& prices) {
		/*
        // DP
        if(prices.size() == 0 || prices.size() == 1)
            return 0;
        int f[prices.size()+1], minnum = prices[0];
        memset(f, 0, sizeof(f));
        for(int i=1; i<prices.size(); i++){
		            f[i] = max(prices[i] - minnum, f[i-1]);
            if(prices[i] < minnum)
                minnum = prices[i];
        }//for
        return f[prices.size()-1];
        */
		// Greedy
		if(prices.size() == 0 || prices.size() == 1)
			return 0;
		int ans = 0;
		int buy = min(prices[0], prices[1]);
		for(int i=1; i<prices.size(); i++){
			ans = max(ans, prices[i] - buy);
			buy = min(buy, prices[i]);
		}//for
		return ans;
	}
};
