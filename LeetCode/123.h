/*
  123. Best Time to Buy and Sell Stock III
  Time: O(n)
  Space: O(n)
*/
class Solution {
 public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() <= 1)
			return 0;
		int ans = 0;
		int inOrder[prices.size()+1], minnum = prices[0];
		memset(inOrder, 0, sizeof(inOrder));
		for(int i=1; i<prices.size(); i++){
			inOrder[i] = max(prices[i] - minnum, inOrder[i-1]);
			if(prices[i] < minnum)
				minnum = prices[i];
		}//for

		int reOrder[prices.size()+1], maxnum = prices[prices.size()-1];
		memset(reOrder, 0, sizeof(reOrder));
		for(int i=prices.size()-2; i>=0; i--){
			reOrder[i] = max(maxnum - prices[i], reOrder[i+1]);
			if(prices[i] > maxnum)
				maxnum = prices[i];
		}//for

		ans = inOrder[prices.size()-1];
		for(int i=0; i<prices.size()-1; i++)
			ans = max(ans, inOrder[i] + reOrder[i+1]);

		return ans;
	}
};
