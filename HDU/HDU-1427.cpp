/*
 * HDU-1427
 * Hint: dfs
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

const int aim = 24;
char kard[4][2];
int num[4];
bool vis[5];
bool found;

void dfs(int left){
    if(found)
        return;
    if(left == 0){
        for(int i=0; i<4; i++)
            if(!vis[i] && num[i] == aim)
                found = true;
        return;
    }
    //choose num[i] and num[j], num[i] = num[i] +/-/8// num[j] or num[i] = num[j] +/-/*// num[i]
    for(int i=0; i<4; i++){
        if(!vis[i]){
            for(int j=i+1; j<4; j++){
                if(vis[j])
                    continue;
                vis[j] = true;
                int x = num[i], y = num[j];
                if(y && x%y==0){
                    num[i] = x/y;
                    dfs(left-1);
                }
                if(x && y%x==0){
                    num[i] = y/x;
                    dfs(left-1);
                }
                num[i] = x-y;
                dfs(left-1);
                num[i] = y-x;
                dfs(left-1);
                num[i] = x+y;
                dfs(left-1);
                num[i] = x*y;
                dfs(left-1);
                num[i] = x;
                vis[j] = false;
            }//for
        }//for
    }//for
    return;
}

int main(){
    while(~scanf("%s %s %s %s", kard[0], kard[1], kard[2], kard[3])){
        for(int i=0; i<4; i++){
            if(kard[i][0] == '1' && kard[i][1] == '0'){
                num[i] = 10;
            }else if(kard[i][0] == 'A'){
                num[i] = 1;
            }else if(kard[i][0] == '2')
                num[i] = 2;
            else if(kard[i][0] == '3')
                num[i] = 3;
            else if(kard[i][0] == '4')
                num[i] = 4;
            else if(kard[i][0] == '5')
                num[i] = 5;
            else if(kard[i][0] == '6')
                num[i] = 6;
            else if(kard[i][0] == '7')
                num[i] = 7;
            else if(kard[i][0] == '8')
                num[i] = 8;
            else if(kard[i][0] == '9')
                num[i] = 9;
            else if(kard[i][0] == 'J')
                num[i] = 11;
            else if(kard[i][0] == 'Q')
                num[i] = 12;
            else if(kard[i][0] == 'K')
                num[i] = 13;
        }//for
        found = false;
        memset(vis, 0, sizeof(vis));
        dfs(3);
        if(found)
            printf("Yes\n");
        else
            printf("No\n");
    }//while
}
