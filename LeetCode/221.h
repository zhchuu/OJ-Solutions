/*
    221. Maximal Square
    Time: O(n^2)
    Space: (n^2)
*/
class Solution {
 public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if(matrix.empty())
			return 0;
		int height = matrix.size(), width = matrix[0].size(), ans = 0;
		int F[height][width];
		memset(F, 0, sizeof(F));
		for(int i=0; i<height; i++){
			F[i][0] = (matrix[i][0]-48)?1:0;
			ans = max(ans, F[i][0]);
		}
		for(int j=0; j<width; j++){
			F[0][j] = (matrix[0][j]-48)?1:0;
			ans = max(ans, F[0][j]);
		}

		/*
        F[i][j] represents the maximum side length of square whose bottom right corner is (i, j)
        F[i][j] = min(F[i-1][j], F[i][j-1], F[i-1][j-1]) + 1 if matrix[i][j] == '1' else 0
        */
		for(int i=1; i<height; i++){
			for(int j=1; j<width; j++){
				if(matrix[i][j]-48){
					F[i][j] = min(min(F[i-1][j], F[i][j-1]), F[i-1][j-1]) + 1;
					ans = max(ans, F[i][j]);
				}

			}//for
		}//for

		return ans*ans;
	}
};
