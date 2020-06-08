/*
    406. Queue Reconstruction by Height
*/
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int vis[people.size()];
        memset(vis, 0, sizeof(vis));
        vector<vector<int>> ans(people.size(), vector<int>());
        sort(people.begin(), people.end(), cmp);
        
        for(int i=0; i<people.size(); i++){
            int idx = people[i][1];
            int cnt = -1, j;
            for(j=0; j<ans.size(); j++){
                if(vis[j] == 0)
                    cnt++;
                if(cnt == idx)
                    break;
            }//for
            ans[j] = people[i];
            vis[j] = 1;
        }//for

        return ans;
    }
};
