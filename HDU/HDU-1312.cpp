/*
 * HDU-1312
 * Hint: dfs
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 20+2;
int mov[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char map[maxn][maxn];
int ans, W, H;

void dfs(int x, int y){
    if(map[x][y] == '#')
        return;
    ans += 1;
    map[x][y] = '#';
    int nxt_x, nxt_y;
    for(int i=0; i<4; i++){
        nxt_x = x + mov[i][0];
        nxt_y = y + mov[i][1];
        if(nxt_x<0 || nxt_x >= H || nxt_y<0 || nxt_y >= W)
            continue;
        dfs(nxt_x, nxt_y);
    }
}

int main(){
    int xx, yy;
    while(~scanf("%d %d", &W, &H) && W && H){
        for(int i=0; i<H; i++){
            scanf("%s", map[i]);
            for(int j=0; j<W; j++){
                if(map[i][j] == '@'){
                    xx = i;
                    yy = j;
                }
            }
        }//input
        ans = 0;
        dfs(xx, yy);
        printf("%d\n", ans);
    }
    return 0;
}
