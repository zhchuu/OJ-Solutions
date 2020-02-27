/*
 * HDU-1072
 * Hint: bfs, priority_queue
 * Always remember to initialize everything in global variables
 * */
#include<stdio.h>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;

struct node{
    int x, y, left, step;
}beg, nxt, tmp;

struct cmp{
    bool operator()(node a, node b){
        return a.step > b.step;
    }
};

const int maxn = 8+2;
int maze[maxn][maxn], N, M;
priority_queue<node, vector<node>, cmp> pq;
int mov[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};

int bfs(int x, int y){
    while(!pq.empty())//don't forget it plz
        pq.pop();
    beg.x = x; beg.y = y; beg.left = 6; beg.step = 0;
    pq.push(beg);
    int ret = -1;
    while(!pq.empty()){
        tmp = pq.top(); pq.pop();
        if(tmp.left <= 0)
            continue;
        else if(maze[tmp.x][tmp.y] == 4){
            tmp.left = 6;
            maze[tmp.x][tmp.y] = 0;//doesn't need to come back
        }
        else if(maze[tmp.x][tmp.y] == 3){
            ret = tmp.step;
            break;
        }
        for(int i=0; i<4; i++){
            int n_x = tmp.x + mov[i][0];
            int n_y = tmp.y + mov[i][1];
            if(n_x >= 0 && n_y >=0 && n_x < N && n_y < M && maze[n_x][n_y] != 0){
                nxt.x = n_x;
                nxt.y = n_y;
                nxt.left = tmp.left - 1;
                nxt.step = tmp.step + 1;
                pq.push(nxt);
            }//if
        }//for
    }//while
    return ret;
}

int main(){
    int kase, start, end;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            scanf("%d", &maze[i][j]);
            if(maze[i][j] == 2){
                start = i;
                end = j;
            }
        }
        maze[start][end] = 0;
        int ans = bfs(start, end);
        printf("%d\n", ans);
    }//while
    return 0;
}
