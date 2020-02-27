/*
 * HDU-2612
 * Hint: bfs
 * */
#include<iostream>
#include<stdio.h>
#include<memory.h>
#include<queue>
using namespace std;

const int maxn = 200;
int n,m;
char map[maxn+5][maxn+5];
int timeY[maxn+5][maxn+5];
int timeM[maxn+5][maxn+5];
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};
int visi[maxn+5][maxn+5];

struct node{
    int x, y, step;
}tmp, now, nxt;

void bfs(int x, int y, int time[][maxn+5]){
    queue<node> qu;
    tmp.x = x; tmp.y = y; tmp.step = 0;
    qu.push(tmp);
    while(!qu.empty()){
        now = qu.front();qu.pop();
        for(int i=0; i<4; i++){//go four directions
            nxt.x = now.x + moveX[i];
            nxt.y = now.y + moveY[i];
            nxt.step = now.step + 1;
            if(nxt.x <= 0 || nxt.x > n || nxt.y <= 0 || nxt.y > m || visi[nxt.x][nxt.y] || map[nxt.x][nxt.y] == '#')
                continue;
            if(map[nxt.x][nxt.y] == '@')//arrive
                time[nxt.x][nxt.y] = nxt.step;
            visi[nxt.x][nxt.y] = 1;
            qu.push(nxt);
        }//for
    }//while
}

int main(){
    int y_x, y_y;
    int m_x, m_y;
    char blank;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            for(int j=1; j<=m; j++){
                cin>>map[i][j];
                if(map[i][j] == 'Y'){
                    y_x = i;
                    y_y = j;
                }else if(map[i][j] == 'M'){
                    m_x = i;
                    m_y = j;
                }
            }
        }
        memset(timeY, -1, sizeof(timeY));
        memset(visi, 0, sizeof(visi));
        bfs(y_x, y_y, timeY);
        memset(timeM, -1, sizeof(timeM));
        memset(visi, 0, sizeof(visi));
        bfs(m_x, m_y, timeM);
        int minTime = 10000;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(map[i][j] == '@' && timeY[i][j] > 0 && timeM[i][j] > 0){
                    minTime = min(minTime, timeY[i][j]+timeM[i][j]);
                }
        cout<<minTime*11<<endl;
    }//while
    return 0;
}
