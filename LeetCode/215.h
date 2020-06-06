/*
    215. Kth Largest Element in an Array
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while(true){
            int pos = partition(nums, left, right);
            if(pos == k-1)
                return nums[pos];
            if(pos > k-1)
                right = pos - 1;
            else
                left = pos + 1;
        }//while
    }

    int partition(vector<int>& nums, int left, int right){
        int mid = nums[left], l = left+1, r = right;
        while(l <= r){
            if(nums[l] < mid && nums[r] > mid)
                swap(nums[l++], nums[r--]);
            if(nums[l] >= mid)
                l++;
            if(nums[r] <= mid)
                r--;
        }//while
        swap(nums[left], nums[r]);
        return r;
    }
};
