class Solution {
 public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int row = obstacleGrid.size();
		int col = obstacleGrid[0].size();
		if(obstacleGrid[0][0] == 1)
			return 0;
		// init
		long t[row][col];
		t[0][0] = 1;
		for(int i=1; i<row; i++){
			if(obstacleGrid[i][0] != 1)
				t[i][0] = t[i-1][0];
			else
				t[i][0] = 0;
		}
		for(int j=1; j<col; j++){
			if(obstacleGrid[0][j] != 1)
				t[0][j] = t[0][j-1];
			else
				t[0][j] = 0;
		}
		// DP
		for(int i=1; i<row; i++){
			for(int j=1; j<col; j++){
				if(obstacleGrid[i][j] != 1)
					t[i][j] = t[i-1][j] + t[i][j-1];
				else
					t[i][j] = 0;
			}//for
		}//for

		return t[row-1][col-1];
	}
};
