/*
    303. Range Sum Query - Immutable
    DP
*/
class NumArray {
public:
    int dp[20000];
    vector<int> vec;
    NumArray(vector<int>& nums) {
        vec = nums;
        for(int i=0; i<=nums.size(); i++)
            dp[i] = INT_MIN;
        if(nums.size() != 0)
            dp[0] = nums[0];
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return getSum(j);
        return getSum(j) - getSum(i-1);
    }

    int getSum(int n){
        if(dp[n] != INT_MIN)
            return dp[n];
        return dp[n] = (vec[n] + getSum(n-1));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
