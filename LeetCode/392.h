/*
    392. Is Subsequence
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int dp[s.length()+1][t.length()+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<s.length(); i++){
            if(s[i] == t[0])
                dp[i+1][1] = 1;
        }//for
        for(int j=0; j<t.length(); j++){
            if(t[j] == s[0])
                dp[1][j+1] = 1;
        }//for
        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=t.length(); j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }//if-else
            }//for
        }//for

        if(dp[s.length()][t.length()] == s.length())
            return true;
        return false;
    }
};
