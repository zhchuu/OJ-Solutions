/*
    17. Letter Combinations of a Phone Number
    Time: O(3^N x 4^M)
    Space: O(3^N x 4^M)
*/
class Solution {
 public:
	vector<string> ans;
	map<char, string> d2c;
	vector<string> letterCombinations(string digits) {
		d2c['2'] = "abc";
		d2c['3'] = "def";
		d2c['4'] = "ghi";
		d2c['5'] = "jkl";
		d2c['6'] = "mno";
		d2c['7'] = "pqrs";
		d2c['8'] = "tuv";
		d2c['9'] = "wxyz";
		if(digits.length() == 0)
			return ans;
		vector<string> tmp;
		tmp.push_back("");
		ans = mySolve(tmp, 0, digits);
		return ans;
	}

	vector<string> mySolve(vector<string> tmp, int pos, string digits){
		if(pos == digits.length())
			return tmp;
		vector<string> nxt_tmp;
		char cur_digit = digits[pos];
		for(int i=0; i<tmp.size(); i++){
			string s = tmp[i];
			for(int j=0; j<d2c[cur_digit].length(); j++){
				nxt_tmp.push_back(s+d2c[cur_digit][j]);
			}
		}//for

		return mySolve(nxt_tmp, pos+1, digits);
	}
};
