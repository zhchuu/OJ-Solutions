class Solution {
 public:
	int searchInsert(vector<int>& nums, int target) {
		return binSearch(nums, target, 0, nums.size()-1);
	}

	int binSearch(vector<int>& nums, int target, int from, int to){
		int lo = from;
		int hi = to;
		while(lo < hi){
			int mid = lo + (hi - lo + 1) / 2;
			if(nums[mid] == target)
				return mid;
			if(nums[mid] > target)
				hi = mid - 1;
			else
				lo = mid + 1;
		}//while
		if(nums[hi] == target)
			return hi;
		if(nums[hi] > target)
			return max(0, hi-1);
		else
			return hi+1;
	}
};
