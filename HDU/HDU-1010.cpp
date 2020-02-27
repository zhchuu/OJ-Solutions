/*
 * HDU-1010
 * Hint: dfs with pruning
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

char maze[10][10];
int N, M, T;
int end_x, end_y;
int sta_x, sta_y;
int mov[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
bool found;

void dfs(int x, int y, int t){
    if(found == true)
        return;
    //int remain = abs(end_x-x) + abs(end_y-y) - t;
    if(t < abs(end_x-x) + abs(end_y-y) || (t-abs(end_x-x)-abs(end_y-y))&1){//pruning
                                                                        //if there's too little time left or
                                                                        //if the parity between time and minimal step are different
        return;
    }
    if(t == 0){
        if(x == end_x && y == end_y)
            found = true;
        return;
    }else{
        for(int i=0; i<4; i++){//go four directions
            int now_x = x + mov[i][0];
            int now_y = y + mov[i][1];
            if(now_x < 0 || now_y < 0 || now_x >= N || now_y >= M || maze[now_x][now_y] == 'X')
                continue;
            //char tmp = maze[now_x][now_y];
            maze[now_x][now_y] = 'X';
            dfs(now_x, now_y, t-1);
            maze[now_x][now_y] = '.';
        }//for
    }//if-else
    return;
}

int main(){
    while(~scanf("%d%d%d", &N, &M, &T) && (N || M || T)){
        for(int i=0; i<N; i++){
            scanf("%s", maze[i]);
            for(int j=0; j<M; j++){
                if(maze[i][j] == 'S'){
                    sta_x = i;
                    sta_y = j;
                    maze[i][j] = 'X';
                }else if(maze[i][j] == 'D'){
                    end_x = i;
                    end_y = j;
                }//if-else
            }//for
        }//for
        found = false;
        dfs(sta_x, sta_y, T);
        if(found)
            printf("YES\n");
        else
            printf("NO\n");
    }//while
}
