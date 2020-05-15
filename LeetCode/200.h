/*
    200. Number of Islands
    DFS
    Time: O(n^2)
    Space: O(n^2)
*/
class Solution {
 public:
	int mov[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	int cnt;

	int numIslands(vector<vector<char>>& grid) {
		if(grid.size() == 0)
			return 0;
		int h = grid.size(), w = grid[0].size();
		int vis[h*w+1];
		memset(vis, 0, sizeof(vis));

		cnt = 0;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(grid[i][j] == '0' || vis[i*w+j] > 0)
					continue;
				cnt++;
				dfs(grid, vis, h, w, i, j);
			}//for
		}//for

		return cnt;
	}

	void dfs(vector<vector<char>>& grid, int vis[], int h, int w, int i, int j){
		if(i<0 || j<0 || i>= h || j>= w || vis[i*w+j] > 0 || grid[i][j] == '0')
			return;
		vis[i*w+j] = cnt;
		for(int k=0; k<4; k++){
			int n_i = i + mov[k][0];
			int n_j = j + mov[k][1];
			dfs(grid, vis, h, w, n_i, n_j);
		}//for
	}
};
