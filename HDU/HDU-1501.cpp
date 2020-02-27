/*
 * HDU-1501
 * Hint: dfs*/

#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

const int maxl = 200+5;
char astr[maxl];
char bstr[maxl];
char cstr[2*maxl];
int kase;
bool found;
bool vis[maxl][maxl];

void dfs(int a, int b, int c){
    if(found)
        return;
    if(a == strlen(astr)-1 && b == strlen(bstr)-1 && c == strlen(cstr)-1){
        found = true;
        return;
    }
    if(a+1 <= strlen(astr)-1 && c+1 <= strlen(cstr)-1 && astr[a+1] == cstr[c+1] && !vis[a+2][b+1]){
        dfs(a+1, b, c+1);
        vis[a+2][b+1] = true;
    }
    if(b+1 <= strlen(bstr)-1 && c+1 <= strlen(cstr)-1 && bstr[b+1] == cstr[c+1] && !vis[a+1][b+2]){
        dfs(a, b+1, c+1);
        vis[a+1][b+2] = true;
    }
    return;
}

int main(){
    scanf("%d", &kase);
    for(int i=0; i<kase; i++){
        scanf("%s %s %s", astr, bstr, cstr);
        found = false;
        memset(vis, 0, sizeof(vis));
        dfs(-1, -1, -1);
        if(found)
            printf("Data set %d: yes\n", i+1);
        else
            printf("Data set %d: no\n", i+1);
    }//for   
}
