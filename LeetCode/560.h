/*
    560. Subarray Sum Equals K
*/
class Solution {
 public:
	int subarraySum(vector<int>& nums, int k) {
		/*
         * Cumulative Sum
         * Time: O(n^2)
         * Space: O(n)
         */
		/**********************************************
        int F[nums.size()+1], ans=0;
        F[0] = 0;
        for(int i=1; i<=nums.size(); i++)
            F[i] = F[i-1] + nums[i-1];

        for(int i=0; i<=nums.size(); i++){
		            for(int j=i+1; j<=nums.size(); j++){
					                if(F[j] - F[i] == k)
                    ans++;
            }//for
        }//for
        return ans;
        ***********************************************/

		/*
         * Hashmap
         * Time: O(n)
         * Space: O(n)
         */
		map<int, int> m;
		int ans=0, sum=0;
		m[0] = 1;
		for(int i=0; i<nums.size(); i++){
			sum += nums[i];
			if(m.count(sum - k))
				ans += m[sum - k];
			if(m.count(sum))
				m[sum] = m[sum] + 1;
			else
				m[sum] = 1;
		}//for
		return ans;
	}
};
