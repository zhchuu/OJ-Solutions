/*
    287. Find the Duplicate Number
    Time: O(n)
    Space: O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int pFast, pSlow, begin;
        for(int i=0; i<nums.size(); i++){
            if(i != nums[i]){
                pSlow = i;
                pFast = nums[i];
                begin = i;
                break;
            }//if
        }//for

        // Meet in cycle
        while(pFast != pSlow){
            pFast = nums[nums[pFast]];
            pSlow = nums[pSlow];
        }//while

        // Count the length of cycle
        int cnt = 1;
        pFast = nums[pFast];
        while(pFast != pSlow){
            pFast = nums[nums[pFast]];
            pSlow = nums[pSlow];
            cnt++;
        }//while

        pFast = begin;
        pSlow = begin;
        for(int i=0; i<cnt; i++)
            pFast = nums[pFast];

        while(pFast != pSlow){
            pFast = nums[pFast];
            pSlow = nums[pSlow];
        }//while

        return pFast;
    }
};
