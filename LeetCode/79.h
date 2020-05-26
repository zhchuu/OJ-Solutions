/*
    79. Word Search
*/

class Solution {
public:
    string target;
    int mov[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int width, height;
    bool exist(vector<vector<char>>& board, string word) {
        height = board.size();
        width = board[0].size();
        target = word;
        int vis[height*width+1];
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                memset(vis, 0, sizeof(vis));
                vis[i*width+j] = 1;
                if(dfs(board, vis, i, j, 0))
                    return true;
            }//for
        }//for
        return false;
    }

    bool dfs(vector<vector<char>>& board, int vis[], int i, int j, int cnt){
        if(cnt >= target.length() || board[i][j] != target[cnt])
            return false;
        if(cnt == target.length() - 1)
            return true;
        bool ret = false;
        for(int k=0; k<4; k++){
            int nxt_i = i + mov[k][0];
            int nxt_j = j + mov[k][1];
            int pos = nxt_i * width + nxt_j;
            if(0 <= nxt_i && nxt_i < height && 0 <= nxt_j && nxt_j < width && !vis[pos]){
                vis[pos] = 1;
                ret = ret || dfs(board, vis, nxt_i, nxt_j, cnt+1);
                vis[pos] = 0;
            }
        }//for
        return ret;
    }
};
