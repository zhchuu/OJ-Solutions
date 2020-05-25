/*
    78. Subsets
    Time: O(2^n)
    Space: O(1)
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<pow(2, n); i++){
            ans.push_back(getVec(nums, i));
        }//for
        return ans;
    }

    vector<int> getVec(vector<int>& nums, int bits){
        vector<int> ret;
        int k = 0;
        while((bits >> k) != 0){  // Check every bit
            if((bits >> k) & 1)
                ret.push_back(nums[nums.size() - k - 1]);
            k++;
        }//while
        return ret;
    }
};
