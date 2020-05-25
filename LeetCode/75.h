/*
    75. Sort Colors
    Time: O(n)
    Space: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty())
            return;
        int left = 0, right = nums.size()-1;
        for(int k=left; k<=right; k++){
            if(nums[k]==0)
                swap(nums[left++], nums[k]);
            else if(nums[k] == 2){
                while(right > k && nums[right] == 2)
                    right--;
                swap(nums[right], nums[k]);
                if(nums[k] == 0)
                    k--;
            }//else-if
        }//for
    }
};
