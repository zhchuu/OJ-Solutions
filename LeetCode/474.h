/*
 * Leetcode 474. Ones and Zeroes
 * 2-D Packing
 */
class Solution {
 public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		int zerosCost[strs.size()];
		int onesCost[strs.size()];
		for(int i=0; i<strs.size(); i++){
			vector<int> zeroOne = getNumOfZeroOne(strs[i]);
			zerosCost[i] = zeroOne[0];
			onesCost[i] = zeroOne[1];
		}//for
		vector<vector<int>> F(m+1, vector<int>(n+1, 0));

		for(int k=0; k<strs.size(); k++)
			for(int i=m; i>=zerosCost[k]; i--)
				for(int j=n; j>=onesCost[k]; j--)
					F[i][j] = max(F[i][j], F[i-zerosCost[k]][j-onesCost[k]] + 1);

		return F[m][n];
	}

	vector<int> getNumOfZeroOne(string str){
		vector<int> ans(2, 0);
		for(auto& i : str){
			if(i == '0') ans[0] += 1;
			else ans[1] += 1;
		}
		return ans;
	}
};
