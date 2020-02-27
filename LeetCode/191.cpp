/*
 * LeetCode 191.Number of 1 Bits
 * */

class Solution{
public:
    int hammingWeight(uint32_t n){
        unsigned int cnt = 0;
        for(cnt=0; n; cnt++)
            n &= (n-1);
        return cnt;
    }
};
