/*
    279. Perfect Squares
*/
class Solution {
public:
    int numSquares(int n) {
        int maxlen = sqrt(n) + 1;
        vector<int> squares(maxlen + 1, 0);

        for(int i=0; i<=maxlen; i++)
            squares[i] = i * i;

        int depth = 0;
        // bfs
        queue<int> qu;
        qu.push(n);
        while(!qu.empty()){
            depth++;
            for(int i=qu.size(); i>0; i--){
                int num = qu.front(); qu.pop();
                for(int j=1; squares[j] <= num; j++){
                    int offset = num - squares[j];
                    if(offset == 0)
                        return depth;
                    else
                        qu.push(offset);
                }//for
            }//for
        }//while

        return depth;
    }
};
