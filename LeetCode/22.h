/*
    22. Generate Parentheses
*/
class Solution {
 public:
	int N;
	vector<string> ans;
	vector<string> generateParenthesis(int n) {
		N = n;
		mySolve("", 0, 0);
		return ans;
	}

	void mySolve(string str, int nonMatch, int cntLeftUsed){
		if(nonMatch == 0 && cntLeftUsed == N){
			ans.push_back(str);
			return;
		}//if
		if(nonMatch == 0)
			mySolve(str+'(', nonMatch+1, cntLeftUsed+1);
		else{
			if(cntLeftUsed < N)
				mySolve(str+'(', nonMatch+1, cntLeftUsed+1);
			mySolve(str+')', nonMatch-1, cntLeftUsed);
		}
	}
};
