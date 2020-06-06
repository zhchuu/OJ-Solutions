/*
    139. Word Break
    Time: O(n^2)
    Space: O(n)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // DP
        int dp[s.length()+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i=0; i<s.length(); i++){
            if(!dp[i])
                continue;
            for(int j=i+1; j<s.length()+1; j++){
                bool matched = existMatchedString(s.substr(i, j-i), wordDict);
                if(dp[i] && matched)
                    dp[j] = 1;
            }//for
        }//for
        return dp[s.length()];
    }

    bool existMatchedString(string str, vector<string>& words){
        vector<string>::iterator iter;
        iter = find(words.begin(), words.end(), str);
        if(iter == words.end())
            return false;
        return true;
    }
};
