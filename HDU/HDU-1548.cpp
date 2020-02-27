/*
 * HDU-1548
 * Hint: bfs
 * */
#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;

struct state{
    int cur;
    int times;
}tmp, now, nxt;

const int maxn = 200+5;
int A, B, N;
int K[maxn];
int visi[maxn][maxn];

int bfs(int start, int end){
    queue<state> qu;
    tmp.cur = start;
    tmp.times = 0;
    qu.push(tmp);
    while(!qu.empty()){
        now = qu.front();qu.pop();
        if(now.cur == end)
            return now.times;
        //up
        nxt.cur = now.cur + K[now.cur];
        nxt.times = now.times + 1;
        if(1 <= nxt.cur && nxt.cur <= N && !visi[nxt.cur][nxt.times]){
            qu.push(nxt);
            visi[nxt.cur][nxt.times] = 1;
        }
        //down
        nxt.cur = now.cur - K[now.cur];
        nxt.times = now.times + 1;
        if(1 <= nxt.cur && nxt.cur <= N && !visi[nxt.cur][nxt.times]){
            qu.push(nxt);
            visi[nxt.cur][nxt.times] = 1;
        }
    }
    return -1;
}

int main(){
    while(~scanf("%d", &N) && N){
        scanf("%d %d", &A, &B);
        for(int i=1; i<=N; i++)
            scanf("%d", &K[i]);
        //printf("N:%d start:%d end:%d\n", N,A,B);
        memset(visi, 0, sizeof(visi));
        int ans = bfs(A, B);
        printf("%d\n", ans);
    }
    return 0;
}
