/*
    207. Course Schedule
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> digraph(numCourses, vector<int>());
        vector<int> in(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            vector<int> tmp = prerequisites[i];
            digraph[tmp[1]].push_back(tmp[0]);
            in[tmp[0]]++;
        }//for
        
        queue<int> qu;
        for(int i=0; i<in.size(); i++){
            if(in[i] == 0)
                qu.push(i);
        }//for

        while(!qu.empty()){
            int cour = qu.front();
            qu.pop();
            for(int i=0; i<digraph[cour].size(); i++){
                in[digraph[cour][i]]--;
                if(in[digraph[cour][i]] == 0)
                    qu.push(digraph[cour][i]);
            }//for
        }//while

        for(int i=0; i<in.size(); i++){
            if(in[i] > 0)
                return false;
        }//for

        return true;
    }
};
