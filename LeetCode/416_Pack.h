/*
 * Leetcode 416. Partition Equal Subset Sum
 * ZeroOnePack
 */
class Solution {
 public:
	bool canPartition(vector<int>& nums) {
		int sumOfArr = accumulate(nums.begin(), nums.end(), 0);
		if(sumOfArr%2 != 0)
			return false;

		// define
		int INF = 100000;
		int volumn = sumOfArr / 2;
		int F[nums.size()+1][volumn+1];

		// init
		for(int i=0; i<=nums.size(); i++)
			for(int v=0; v<=volumn; v++)
				F[i][v] = 0;

		//solve
		for(int i=1; i<=nums.size(); i++){
			for(int v=nums[i-1]; v<=volumn; v++){
				F[i][v] = max(F[i-1][v], F[i-1][v-nums[i-1]] + nums[i-1]);
			}//for
		}//for

		// result
		if(F[nums.size()][volumn] == volumn)
			return true;
		return false;
	}
};
