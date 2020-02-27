/*
 * HDU-1181
 * Hint: dfs
 * */

#include<stdio.h>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<string>
using namespace std;

bool visi[10000+5];
vector<string> words;
bool found;
int cnt;
char from, to;
char str[1000];

void dfs(int cur){
    if(found || cur >= cnt)
        return;
    for(int i=0; i<cnt; i++){
        if(words[i][0] == from && words[i][words[i].length()-1] == to && !visi[i]){
            found = true;
            return;
        }//if
        if(!visi[i] && words[i][0] == from){
            char temp = from;
            from = words[i][words[i].length() - 1];
            visi[i] = true;
            dfs(cur+1);
            visi[i] = false;
            from = temp;
        }//if
    }//for
}

int main(){
    //string str;
    while(~scanf("%s", str)){
        from = 'b';
        to = 'm';
        found = false;
        cnt = 0;
        words.clear();
        memset(visi, 0, sizeof(visi));
        while(str[0] != '0'){
            words.push_back(str);
            cnt++;
            scanf("%s", str);
            //str = getchar();
        }
        dfs(0);
        if(found)
            printf("Yes.\n");
        else
            printf("No.\n");
    }//while
    return 0;
}
