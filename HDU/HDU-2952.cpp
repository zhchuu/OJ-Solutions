/*
 * HDU-2952
 * Hint: dfs
 * */
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<memory.h>
using namespace std;

const int maxn = 100+5;
char map[maxn][maxn];
int vis[maxn][maxn];
int mov[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int H, W, now;

void dfs(int x, int y, int tag){
    if(map[x][y] == '.')
        return;
    vis[x][y] = tag;
    for(int i=0; i<4; i++){
        int nxt_x = x + mov[i][0];
        int nxt_y = y + mov[i][1];
        if(nxt_x >= 0 && nxt_y >=0 && nxt_x < H && nxt_y < W && vis[nxt_x][nxt_y] == 0)
            dfs(nxt_x, nxt_y, tag);
    }
}

void work(){
    now = 0;
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            if(map[i][j] == '#' && vis[i][j] == 0)
                dfs(i, j, ++now);
}

int main(){
    int kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d%d", &H, &W);
        for(int i=0; i<H; i++)
            scanf("%s", map[i]);
        work();
        printf("%d\n", now);
    }
}
