/*
 * HDU-3533
 * Hint: bfs
 * */

#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;

const int maxn = 100 + 5;
int n, m, k, energy;
int mov[5][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}, {0,0}};
int map[maxn][maxn];
bool visi[maxn][maxn][1005];//x, y, step
//TLE when using int 

struct castle{
    char c;
    int t,v;
}cas[maxn][maxn];

struct node{
    int x, y, step;
}tmp, now, nxt;

int isOut(int x, int y){
    if(x < 0 || y < 0 || x > n || y > m)
        return 1;
    return 0;
}

int bfs(){
    queue<node> qu;
    tmp.x = tmp.y = tmp.step = 0;
    qu.push(tmp);
    visi[0][0][0] = 1;
    bool die;
    int tem, dis;
    while(!qu.empty()){
        now = qu.front(); qu.pop();
        if(now.step > energy)
            break;
        if(now.x == n && now.y == m)
            return now.step;
        for(int i=0; i<5; i++){//go four directions
            nxt = now;
            nxt.x += mov[i][0];
            nxt.y += mov[i][1];
            nxt.step++;
            if(isOut(nxt.x, nxt.y))
                continue;
            if(visi[nxt.x][nxt.y][nxt.step] || nxt.step > energy || map[nxt.x][nxt.y]) continue;
            die = false;
            //north
            for(int posx = nxt.x - 1; posx >= 0; posx--){//north
                if(map[posx][nxt.y] && cas[posx][nxt.y].c == 'S'){//shoot to south
                    dis = nxt.x - posx;//distance
                    if(dis % cas[posx][nxt.y].v)//bullet never stops at this position
                        break;
                    tem = nxt.step - dis/cas[posx][nxt.y].v;//step minus how much time it needs
                    if(tem < 0)//the first bullet haven't arrived
                        break;
                    if(tem % cas[posx][nxt.y].t == 0){//interval
                        die = true;
                        break;
                    }//if
                }//if
                if(map[posx][nxt.y])//find a castle to block all bullets
                    break;
            }//for
            if(die)
                continue;
            //south
            for(int posx = nxt.x + 1; posx <=n; posx++){
                if(map[posx][nxt.y] && cas[posx][nxt.y].c == 'N'){
                    dis = posx - nxt.x;
                    if(dis % cas[posx][nxt.y].v)
                        break;
                    tem = nxt.step - dis/cas[posx][nxt.y].v;
                    if(tem < 0)
                        break;
                    if(tem % cas[posx][nxt.y].t == 0){
                        die = true;
                        break;
                    }
                }
                if(map[posx][nxt.y])
                    break;
            }//for
            if(die)
                continue;
            //West
            for(int posy = nxt.y - 1; posy >= 0; posy--){
                if(map[nxt.x][posy] && cas[nxt.x][posy].c == 'E'){
                    dis = nxt.y - posy;
                    if(dis % cas[nxt.x][posy].v)
                        break;
                    tem = nxt.step - dis/cas[nxt.x][posy].v;
                    if(tem < 0)
                        break;
                    if(tem % cas[nxt.x][posy].t == 0){
                        die = true;
                        break;
                    }
                }//if
                if(map[nxt.x][posy])
                    break;
            }//for
            if(die)
                continue;
            //East
            for(int posy = nxt.y + 1; posy <= m; posy++){
                if(map[nxt.x][posy] && cas[nxt.x][posy].c == 'W'){
                    dis = posy - nxt.y;
                    if(dis % cas[nxt.x][posy].v)
                        break;
                    tem = nxt.step-dis/cas[nxt.x][posy].v;
                    if(tem < 0)
                        break;
                    if(tem % cas[nxt.x][posy].t == 0){
                        die = true;
                        break;
                    }
                }
                if(map[nxt.x][posy])
                    break;
            }
            if(die)
                continue;
            visi[nxt.x][nxt.y][nxt.step] = true;
            qu.push(nxt);
        }//for
    }//while
    return -1;
}

int main(){
    char str[3];
    int x,y,t,v;
    while(~scanf("%d%d%d%d", &n, &m, &k, &energy)){
        memset(cas, 0, sizeof(cas));
        memset(visi, false, sizeof(visi));
        memset(map, 0, sizeof(map));
        for(int i=0; i<k; i++){
            scanf("%s%d%d%d%d", str, &t, &v, &x, &y);
            cas[x][y].v = v;
            cas[x][y].t = t;
            cas[x][y].c = str[0];
            map[x][y] = 1;
        }//for
        int ans = bfs();
        if(ans == -1)
            printf("Bad luck!\n");
        else
            printf("%d\n", ans);
    }//while
    return 0;
}
