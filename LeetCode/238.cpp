/*
 * LeetCode 238.Product of Array Except Self
 * */

#include<vector>
using namespace std;

class Solution{
public:
    vector<int> productExceptSelf(vector<int>& nums){
        vector<int> ret;
        ret.resize(nums.size());
        ret[0] = 1;
        for(int i=1; i<nums.size(); i++)
            ret[i] = ret[i-1]*nums[i-1];
        int right = 1;
        for(int j=nums.size()-1; j>=0; j--){
            ret[j] = ret[j]*right;
            right = right*nums[j];
        }
        return ret;
    }
};
