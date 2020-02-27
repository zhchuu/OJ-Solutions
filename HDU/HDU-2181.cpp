/*
 * HDU-2181
 * Hint: dfs
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

const int maxn = 20+2;
int map[maxn][3], m, cnt;
bool vis[maxn];
vector<int> store;

void output(){
    printf("%d:  ", ++cnt);
    for(int i=0; i<store.size(); i++)
        printf("%d ", store[i]);
    printf("%d\n", m);
}

void dfs(int now, int total){
    if(total >= 20){
        if(map[now][0] == m || map[now][1] == m || map[now][2] == m)
            output();
        return;
    }//if
    for(int i=0; i<3; i++)
    if(!vis[map[now][i]]){
        vis[map[now][i]] = true;
        store.push_back(map[now][i]);
        dfs(map[now][i], total+1);
        store.pop_back();
        vis[map[now][i]] = false;
    }
}

int main(){
    for(int i=1; i<=20; i++)
        scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
    while(~scanf("%d", &m) && m){
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        store.push_back(m);
        vis[m] = true;
        dfs(m, 1);
    }
    return 0;
}
