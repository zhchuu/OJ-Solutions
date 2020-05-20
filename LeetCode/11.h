/*
    11. Container With Most Water
    Time: O(n)
    Space: O(1)
*/
class Solution {
 public:
	int maxArea(vector<int>& height) {
		int lo = 0, hi = height.size()-1, ans = INT_MIN;
		while(lo < hi){
			ans = max(ans, min(height[lo], height[hi]) * (hi-lo));
			if(height[lo] < height[hi])
				lo++;
			else
				hi--;
		}//while
		return ans;
	}
};
