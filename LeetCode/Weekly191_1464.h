/*
  Weekly Contest 191
  1464. Maximum Product of Two Elements in an Array
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 2)
            return (nums[0]-1)*(nums[1]-1);

        int maxnum = max(nums[0], nums[1]);
        int smaxnum = min(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++){
            if(nums[i] > maxnum){
                smaxnum = maxnum;
                maxnum = nums[i];
            }
                
            else if(nums[i] > smaxnum)
                smaxnum = nums[i];
        }//for

        return (maxnum-1) * (smaxnum-1);
    }
};
