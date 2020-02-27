class Solution {
 public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		// Find a[i]
		int i=0;
		for(i=len-2; i>=0; i--){
			if(nums[i] < nums[i+1])
				break;
		}//for

		// If the current string is the largest. Reverse.
		if(i < 0){
			reverse(nums, 0, len-1);
			return;
		}

		// Find a[k]
		int k=0;
		for(k=len-1; k>i+1; k--){
			if(nums[k] > nums[i])
				break;
		}

		// Swap a[i] and a[k]
		swap(nums, i, k);

		// Reverse a[i+1, ..., len-1]
		reverse(nums, i+1, len-1);
	}
	void reverse(vector<int>& arr, int from, int to){
		for(int i=0; i<(to-from+1)/2; i++){
			int p = from + i;
			int q = to - i;
			int tmp = arr[p];
			arr[p] = arr[q];
			arr[q] = tmp;
		}
	}
	void swap(vector<int>& arr, int p, int q){
		int tmp = arr[p];
		arr[p] = arr[q];
		arr[q] = tmp;
	}
};
