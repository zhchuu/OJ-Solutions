/*
    56. Merge Intervals
    Time: O(nlogn)
    Space: O(1)
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return ans;
        vector<vector<int>>& vec = intervals;
        sort(vec.begin(), vec.end());

        for(int i=0; i<vec.size();){
            int j = i+1, rightmax = vec[i][1];
            while(j<vec.size() && rightmax >= vec[j][0]){
                rightmax = max(rightmax, vec[j][1]);
                j++;
            }//while
            ans.push_back({vec[i][0], rightmax});
            i = j;
        }//for
        
        return ans;
    }
};
