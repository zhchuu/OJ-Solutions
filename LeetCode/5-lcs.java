class Solution {
	public String longestPalindrome(String s) {
		if(s.length() < 2)
			return s;
		return modifiedLCSubstr(s, new StringBuilder(s).reverse().toString());
	}

	public String modifiedLCSubstr(String a, String b){
		int[][] L = new int[a.length()][b.length()];
		int maxLength = 0;
		String ret = new StringBuilder(a.charAt(0)).toString();

		for(int i=0; i<a.length(); i++){
			for(int j=0; j<b.length(); j++){
				if(a.charAt(i) == b.charAt(j)){
					if(i==0 || j==0)
						L[i][j] = 1;
					else
						L[i][j] = L[i-1][j-1] + 1;
					if(L[i][j] > maxLength){  //check if palindromic
						String toBeChecked = a.substring(i-L[i][j]+1, i+1);
						if(check(toBeChecked)){
							ret = toBeChecked;
							maxLength = L[i][j];
						}//if
					}//if
				}else{
					L[i][j] = 0;
				}//if-else
			}//for
		}//for

		return ret;
	}

	public boolean check(String s){
		for(int i=0; i<Math.floor(s.length()/2)+1; i++){
			if(s.charAt(i) != s.charAt(s.length()-i-1))
				return false;
		}//for
		return true;
	}
}
