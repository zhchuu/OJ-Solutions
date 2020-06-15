/*
    787. Cheapest Flights Within K Stops
*/
class Solution {
public:
    struct node{
        int city;
        int cost;
        int stops;
        node(int ci, int co, int st): city(ci), cost(co), stops(st){}
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int table[n+1][n+1];
        memset(table, -1, sizeof(table));
        for(int i=0; i<flights.size(); i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int cost = flights[i][2];
            table[from][to] = cost;
        }//for

        int ans = INT_MAX;
        queue<node> qu;
        node start(src, 0, 0);
        qu.push(start);
        while(!qu.empty()){
            node tmp = qu.front();qu.pop();
            if(tmp.city == dst)
                ans = min(ans, tmp.cost);
            if(tmp.stops > K || tmp.cost >= ans)
                continue;
            else{
                for(int j=0; j<n; j++){
                    if(table[tmp.city][j] != -1){
                        node nxt(j, tmp.cost + table[tmp.city][j], tmp.stops+1);
                        qu.push(nxt);
                    }//if
                }//for
            }//if-else
        }//while

        return ans == INT_MAX ? -1:ans;
    }
};
