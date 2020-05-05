/*
  122. Best Time to Buy and Sell Stock II
  Time: O(n)
  Space: O(1)
*/

class Solution {
 public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() <= 1)
			return 0;
		int ans = 0, buy = 0, sell = 1;
		while(sell < prices.size()){
			while(sell < prices.size() && prices[sell] >= prices[sell-1])
				sell++;
			if(prices[sell - 1] > prices[buy])
				ans += (prices[sell-1] - prices[buy]);
			buy = sell;
			sell = sell + 1;
		}//while
		return ans;
	}
};
