class Solution {
public:
	int uniquePaths(int m, int n) {
		int row = n;
		int col = m;
		int t[row][col];
		// init
		t[0][0] = 1;
		for(int i=0; i<n; i++)
			t[i][0] = 1;
		for(int j=0; j<m; j++)
			t[0][j] = 1;

		// DP
		for(int i=1; i<n; i++){
			for(int j=1; j<m; j++){
				t[i][j] = t[i-1][j] + t[i][j-1];
			}//for
		}//for

		return t[n-1][m-1];
	}
};
