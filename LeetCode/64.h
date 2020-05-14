/*
    64. Minimum Path Sum
    Time: O(n^2)
    Space: O(n^2)
*/
class Solution {
 public:
	int minPathSum(vector<vector<int>>& grid) {
		int height = grid.size(), width = grid[0].size();
		int F[height][width];
		for(int i=0; i<height; i++)
			for(int j=0; j<width; j++)
				F[i][j] = INT_MAX;
		// init
		F[0][0] = grid[0][0];
		for(int i=1; i<height; i++)
			F[i][0] = F[i-1][0] + grid[i][0];
		for(int j=1; j<width; j++)
			F[0][j] = F[0][j-1] + grid[0][j];

		for(int i=1; i<height; i++){
			for(int j=1; j<width; j++){
				F[i][j] = min(F[i-1][j], F[i][j-1]) + grid[i][j];
			}//for
		}//for

		return F[height-1][width-1];
	}
};
