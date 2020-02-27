/*
 * LeetCode 172.Factorial Trailing Zeros
 * */

class Solution{
public:
    int TLEFunction(int n){
        int ret = 0;
        for(int i=5; i<=n; i++){
            int j = i;
            while(j % 5 == 0){
                ret += 1;
                j /= 5;
            }
        }
        return ret;
    }

    int trailingZeroes(int n){
        int ret = 0;
        while(n){
            ret += n/5;
            n /= 5;
        }
        return ret;
    }
};
