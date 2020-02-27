/*
 * HDU-1728
 * Hint: bfs
 * 46ms/62ms, 1832K
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct node{
    int x, y, turn, dir;//dir: 0-down 1-up 2-right 3-left, match with mov[][] below
    node(){}
    node(int xx, int yy, int tt, int dd){
        x = xx; y = yy; turn = tt; dir = dd;
    }
}tmp, nxt;

struct cmp{
    bool operator()(node a, node b){
        return a.turn < b.turn;
    }
};

const int maxn = 100+5;
char maze[maxn][maxn];
int time[maxn][maxn];//the maximum turning times left that arrive at x, y
int mov[4][2] = {1, 0, -1, 0, 0, 1, 0, -1}, m, n;
priority_queue<node, vector<node>, cmp> pq;

void init(){
    while(!pq.empty())
        pq.pop();
    memset(time, -1, sizeof(time));
}

bool bfs(int sx, int sy, int turns, int ex, int ey){
    init();
    node strt(sx, sy, turns+1, -1);
    pq.push(strt);
    while(!pq.empty()){
        tmp = pq.top(); pq.pop();
        //printf("node: %d %d %d %d\n", tmp.x, tmp.y, tmp.turn, tmp.dir);
        if(tmp.x == ex && tmp.y == ey)
            return true;
        for(int i=0; i<4; i++){
            nxt = tmp;
            nxt.x += mov[i][0];
            nxt.y += mov[i][1];
            if(nxt.x <= 0 || nxt.y <= 0 || nxt.x > m || nxt.y > n || maze[nxt.x][nxt.y] == '*')
                continue;
            if(nxt.dir != i)
                nxt.turn -= 1;
            nxt.dir = i;
            if(nxt.turn < 0)
                continue;
            if(nxt.turn >= time[nxt.x][nxt.y]){//pruning
                time[nxt.x][nxt.y] = nxt.turn;
                pq.push(nxt);
            }
        }//for
    }//while
    return false;
}

int main(){
    int kase, k, row1, col1, row2, col2;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d%d", &m, &n);
        for(int i=1; i<=m; i++){
            scanf("%s", maze[i]+1);
            getchar();
        }
        scanf("%d%d%d%d%d", &k, &col1, &row1, &col2, &row2);
        bool ans = bfs(row1, col1, k, row2, col2);
        if(ans)
            printf("yes\n");
        else
            printf("no\n");
    }//while
    return 0;
}
