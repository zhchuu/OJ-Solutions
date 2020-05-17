/*
    678. Valid Parenthesis String
    Time: O(n)
    Space: O(1)
*/
class Solution {
 public:
	bool checkValidString(string s) {
		int minNum=0, maxNum=0;  //Minimum and maximum number of left brackets remaining
		for(int i=0; i<s.length(); i++){
			if(s[i] == '('){
				minNum++;
				maxNum++;
			}
			else if(s[i] == ')'){
				minNum--;
				maxNum--;
			}else{  // '*' could be '(' or ')'
				minNum--;
				maxNum++;
			}
			if(maxNum < 0)
				break;
			minNum = max(minNum, 0);
		}//for
		return minNum == 0;
	}
};
