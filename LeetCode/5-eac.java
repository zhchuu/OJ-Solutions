class Solution {
	public String longestPalindrome(String s) {
		if(s.length() < 2)
			return s;
		int from = 0, to = 0;
		for(int i=0; i<s.length(); i++){
			int len1 = expandAroundCenter(s, i, i);  // odd
			int len2 = expandAroundCenter(s, i, i+1);  // even
			int len = Math.max(len1, len2);
			if(len > to-from){
				from = i - (len-1)/2;
				to = i + len/2;
			}
		}//for

		return s.substring(from, to+1);
	}

	public int expandAroundCenter(String s, int left, int right){
		int L = left, R = right;
		while(L>=0 && R<s.length() && s.charAt(L) == s.charAt(R)){
			L--;
			R++;
		}
		return R-L-1;  // return the length of palindrome
	}
}
