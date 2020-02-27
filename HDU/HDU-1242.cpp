/*
 * HDU-1242
 * Hint: bfs, priority_queue
 * */
#include<stdio.h>
#include<memory.h>
#include<queue>
#include<vector>
using namespace std;

struct node{
    int x, y, step;
}strt, tmp, nxt;

struct cmp{
    bool operator()(node a, node b){
        return a.step > b.step;
    }
};

const int maxn = 200+5;
char maze[maxn][maxn];
int mov[][2] = {0, 1, 0, -1, 1, 0, -1, 0}, N, M;
priority_queue<node, vector<node>, cmp> pq;

void init(){
    while(!pq.empty())
        pq.pop();
}

int bfs(int sx, int sy){
    init();
    strt.x = sx; strt.y = sy; strt.step = 0;
    maze[sx][sy] = '#';
    pq.push(strt);
    while(!pq.empty()){
        tmp = pq.top(); pq.pop();
        for(int i=0; i<4; i++){
            nxt = tmp;
            nxt.x += mov[i][0];
            nxt.y += mov[i][1];
            if(nxt.x<0 || nxt.y<0 || nxt.x>=N || nxt.y>=M || maze[nxt.x][nxt.y] == '#')
                continue;
            if(maze[nxt.x][nxt.y] == '.')
                nxt.step += 1;
            else if(maze[nxt.x][nxt.y] == 'x')
                nxt.step += 2;
            if(maze[nxt.x][nxt.y] == 'a')
                return tmp.step + 1;
            maze[nxt.x][nxt.y] = '#';
            pq.push(nxt);
        }//for
    }//while
    return -1;
}

void showMaze(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int xx, yy;
    while(~scanf("%d%d", &N, &M)){
        for(int i=0; i<N; i++){
            scanf("%s", maze[i]);
            for(int j=0; j<M; j++)
                if(maze[i][j] == 'r'){
                    xx = i; yy = j;
                }
        }//input
        int ans = bfs(xx, yy);
        if(ans == -1)
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        else
            printf("%d\n", ans);
    }//while
    return 0;
}
