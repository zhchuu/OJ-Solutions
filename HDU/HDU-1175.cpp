/*
 * HDU-1175
 * Hint: bfs
 * */

#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;

struct state{
    int x, y;
    int direction;//0-up 1-down 2-left 3-right
    int times;
}start, now, nxt;

int m,n;
int map[1000+5][1000+5];
int moveX[4] = {0,0,1,-1};
int moveY[4] = {1,-1,0,0};
int num[1000+5][1000+5];//The minimal turning times that arrive at x, y

bool bfs(int x1, int y1, int x2, int y2){
    if(map[x1][y1] != map[x2][y2] || !map[x1][y1])
        return false;
    queue<state> qu;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            num[i][j] = 100;
    num[x1][y1] = 0;
    start.x = x1;
    start.y = y1;
    start.direction = -1;
    start.times = 0;
    qu.push(start);
    while(!qu.empty()){
        now = qu.front();
        qu.pop();
        for(int i=0; i<4; i++){
            nxt = now;
            nxt.x += moveX[i];
            nxt.y += moveY[i];
            if(nxt.x <= 0 || nxt.y <= 0 || nxt.x > n || nxt.y > m)//outside the map
                continue;
            if(nxt.direction != i)
                nxt.times++;
            nxt.direction = i;
            if(nxt.times > 3)
                continue;
            if(nxt.x == x2 && nxt.y == y2)
                return true;
            if(map[nxt.x][nxt.y])//important
                continue;
            if(nxt.times < num[nxt.x][nxt.y]){//if not, TLE
                num[nxt.x][nxt.y] = nxt.times;
                qu.push(nxt);
            }
        }
    }
    return false;
}

int main(){
    while(scanf("%d%d", &n,&m) && (n||m)){
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                scanf("%d", &map[i][j]);
        int q;
        scanf("%d",&q);
        while(q--){
            int x1, y1, x2, y2;
            scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
            if(bfs(x1,y1,x2,y2))
                printf("YES\n");
            else 
                printf("NO\n");
        }
    }
    return 0;
}
