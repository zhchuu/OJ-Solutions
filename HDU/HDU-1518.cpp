/*
 * HDU-1518
 * Hint: dfs
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<functional>
using namespace std;

const int maxn = 20+5;
int kase, cnt, avg;
bool vis[maxn];
int num[maxn];
bool found;

void dfs(int left, int times, int idx){
    if(found)
        return;
    if(left == 0 && times == 1){
        found = true;
        return;
    }else if(left == 0){
        dfs(avg, times-1, 0);
    }//else-if
    for(int i=idx; i<cnt; i++){//search from idx, pruning, from TLE to 405MS
//        if(i && num[i] == num[i-1] && !vis[i-1])//pruning, from 405MS to 436MS, why
//            continue;
        if(!vis[i] && (left - num[i] >= 0)){
            vis[i] = true;
            dfs(left - num[i], times, i+1);
            vis[i] = false;
        }//if
    }//for
    return;
}

int main(){
    scanf("%d", &kase);
    while(kase--){
        int sum = 0;
        scanf("%d", &cnt);
        for(int i=0; i<cnt; i++){
            scanf("%d", &num[i]);
            sum += num[i];
        }//for
        if(sum%4 != 0){
            printf("no\n");
            continue;
        }
        sort(num, num+cnt, greater<int>());
        if(num[0] > sum/4){
            printf("no\n");
            continue;
        }
        found = false;
        avg = sum/4;
        memset(vis, 0, sizeof(vis));
        dfs(avg, 4, 0);
        if(found)
            printf("yes\n");
        else
            printf("no\n");
    }//while
    return 0;
}
