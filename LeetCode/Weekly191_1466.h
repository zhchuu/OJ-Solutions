/*
  Weekly Contest 191
  1466. Reorder Routes to Make All Paths Lead to the City Zero
*/
class Solution {
public:
    int ans;
    int minReorder(int n, vector<vector<int>>& connections) {
        ans = 0;
        vector<vector<int>> table(n);
        vector<int> vis(n);
        for(int i=0; i<connections.size(); i++){
            table[connections[i][0]].push_back(connections[i][1]);
            table[connections[i][1]].push_back(-connections[i][0]);
        }//for
        dfs(table, vis, 0);
        return ans;
    }

    void dfs(vector<vector<int>> &table, vector<int> &vis, int cur){
        vis[cur] = 1;
        for(int i=0; i<table[cur].size(); i++){
            int nxt = table[cur][i];
            if(vis[abs(nxt)])
                continue;
            if(nxt > 0)
                ans++;
            dfs(table, vis, abs(nxt));
        }//for
    }

};
