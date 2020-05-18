/*
    1143. Longest Common Subsequence
    Time: O(n^2)
    Space: O(n^2)
*/
class Solution {
 public:
	int longestCommonSubsequence(string text1, string text2) {
		/*
            F[i][j] reresents the LCS of text1[0~i] and text2[0~j], inclusive.
            if text1[i] == text2[j]:
                F[i][j] = F[i-1][j-1] + 1
            else:
                F[i][j] = max(F[i-1][j], F[i][j-1])
		*/
		int F[text1.length()+1][text2.length()+1];
		memset(F, 0, sizeof(F));
		if(text1[0] == text2[0])
			F[0][0] = 1;
		for(int i=1; i<text1.length(); i++)
			F[i][0] = max(F[i-1][0], text1[i] == text2[0]?1:0);
		for(int j=1; j<text2.length(); j++)
			F[0][j] = max(F[0][j-1], text1[0] == text2[j]?1:0);

		for(int i=1; i<text1.length(); i++){
			for(int j=1; j<text2.length(); j++){
				if(text1[i] == text2[j])
					F[i][j] = F[i-1][j-1] + 1;
				else
					F[i][j] = max(F[i-1][j], F[i][j-1]);
			}//for
		}//for

		return F[text1.length()-1][text2.length()-1];
	}
};
