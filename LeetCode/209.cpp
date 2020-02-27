/*
 * LeetCode 209.Minimum Size Subarray Sum
 * Hint: Moving window
 * */
#include<vector>
using namespace std;

class Solution{
public:
    int minSubArrayLen(int s, vector<int>& nums){
        int i = 0, j = 0, sum = 0, ret = 99999;
        while(j < nums.size()){
            while(sum < s && j < nums.size())
                sum += nums[j++];
            if(sum >= s){
                while(sum >= s && i < j){
                    //if(sum == s)
                    //    ret = min(ret, j-i);
                    sum -= nums[i++];
                }
                ret = min(ret, j-i+1);
            }
        }//while
        return ret == 99999 ? 0 : ret;
    }
};
