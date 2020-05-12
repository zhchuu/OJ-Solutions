/*
    33. Search in Rotated Sorted Array
    Time: O(logn)
    Space: (1)
*/
class Solution {
 public:
	int search(vector<int>& nums, int target) {
		if(nums.size() == 0)
			return -1;

		int lo = 0, hi = nums.size()-1, mid;
		while(lo <= hi){
			mid = (hi - lo) / 2 + lo;
			if(nums[mid] == target)
				return mid;

			if(nums[lo] <= nums[mid]){
				if(nums[lo] <= target && target < nums[mid])  // (lo, mid) is ascending
					hi = mid-1;
				else
					lo = mid+1;
			}else{
				if(nums[mid] < target && target <= nums[hi])  // (mid, hi) is ascending
					lo = mid+1;
				else
					hi = mid-1;
			}//if-else
		}//while

		return -1;
	}
};
