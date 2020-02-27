/*
 * HDU-1258
 * Hint: dfs
 * */
#include<stdio.h>
#include<memory>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int t, n;
int num[15];
bool visi[15];
vector<vector<int>> ans;
vector<int> temp_res;
set<vector<int>> dup;

void dfs(int cur, int sum){
    if(sum == t){
        if(dup.count(temp_res) == 0){
            ans.push_back(temp_res);
            dup.insert(temp_res);
        }
        return;
    }//if
    for(int i=cur; i<n; i++){
        if(visi[i] || sum + num[i] > t)
            continue;
        visi[i] = true;
        temp_res.push_back(num[i]);
        dfs(i+1, sum + num[i]);
        temp_res.pop_back();
        visi[i] = false;
    }//for
    return;
}

int main(){
    while(~scanf("%d%d",&t, &n) && (t || n)){
        for(int i=0; i<n; i++)
            scanf("%d", &num[i]);
        ans.clear();
        temp_res.clear();
        printf("Sums of %d:\n", t);
        dfs(0, 0);
        if(ans.size() == 0)
            printf("NONE\n");
        else{
            for(int i=0; i<ans.size(); i++){
                printf("%d", ans[i][0]);
                for(int j=1; j<ans[i].size(); j++){
                    printf("+%d", ans[i][j]);
                }//for
                printf("\n");
            }//for
        }//if-else
    }//while
}
