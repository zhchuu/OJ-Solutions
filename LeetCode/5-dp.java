class Solution {
	public String longestPalindrome(String s) {
		if(s.length() < 2)
			return s;
		// initialize
		int[][] L = new int[s.length()+1][s.length()+1];
		for(int i=0; i<s.length()-1; i++){
			L[i][i] = 1;
			if(s.charAt(i) == s.charAt(i+1))
				L[i][i+1] = 1;
		}//for
		L[s.length()-1][s.length()-1] = 1;

		// DP
		for(int k=2; k<s.length(); k++){ // length of substring
			for(int i=0; i<s.length()-k; i++){
				int j =i+k;
				if(L[i+1][j-1]==1 && s.charAt(i)==s.charAt(j))
					L[i][j] = 1;
			}//for
		}//for

		// result
		int maxLength = -1, from = 0, to = 0;
		for(int i=0; i<s.length(); i++){
			for(int j=i; j<s.length(); j++){
				if(L[i][j] == 1 && (j-i)>maxLength){
					maxLength = j-i;
					from = i;
					to = j;
				}//if
			}//for
		}//for

		return s.substring(from, to+1);
	}
}
