/*
    1029. Two City Scheduling
*/
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        int offsetA = abs(a[0] - a[1]);
        int offsetB = abs(b[0] - b[1]);
        return (offsetA > offsetB);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int a_left = costs.size() / 2;
        int b_left = costs.size() / 2;
        int ans = 0;
        sort(costs.begin(), costs.end(), cmp);

        for(int i=0; i<costs.size(); i++){
            //cout << costs[i][0] << " " << costs[i][1] << endl;
            if(costs[i][0] < costs[i][1]){
                if(a_left > 0){
                    a_left--;
                    ans += costs[i][0];
                }else{
                    b_left--;
                    ans += costs[i][1];
                }
            }else{
                if(b_left > 0){
                    b_left--;
                    ans += costs[i][1];
                }else{
                    a_left--;
                    ans += costs[i][0];
                }
            }
        }//for

        return ans;
    }
};
