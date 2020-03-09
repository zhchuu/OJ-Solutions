/*
 * Leetcode 416. Partition Equal Subset Sum
 * ZeroOnePack with optimization on memory
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
		int F[volumn+1];

		// init
		for(int v=0; v<=volumn; v++)
			F[v] = 0;

		//solve
		for(int i=1; i<=nums.size(); i++){
			for(int v=volumn; v>=nums[i-1]; v--){
				F[v] = max(F[v], F[v-nums[i-1]] + nums[i-1]);
			}//for
		}//for

		// result
		if(F[volumn] == volumn)
			return true;
		return false;
	}
};
