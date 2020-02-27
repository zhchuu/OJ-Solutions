/*
 * HDU-1495
 * Hint: bfs
 * */

#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;

struct state{
    int a, b, c, times;
}temp, now;

int visi[101+5][101+5][101+5];

void bfs(int a, int b, int c){
    memset(visi, 0, sizeof(visi));
    queue<state> qu;
    temp.a = a; temp.b = 0; temp.c = 0; temp.times = 0;
    qu.push(temp);
    while(!qu.empty()){
        temp = qu.front(); 
        visi[temp.a][temp.b][temp.c] = 1;//record status 
        if((temp.a == a/2 && temp.b == a/2) || (temp.a == a/2 && temp.c == a/2) || (temp.b == a/2 && temp.c == a/2))
            break;
        qu.pop();
        //a
        if(temp.a != 0){
            if(temp.a > b-temp.b){//fill b, a has water left
                now.a  = temp.a - (b - temp.b);
                now.b = b;
                now.c = temp.c;
                now.times = temp.times+1;
            }else{//pour to b, a become empty
                now.a = 0;
                now.b = temp.b + temp.a;
                now.c = temp.c;
                now.times = temp.times+1;
            }
            //record status
            if(!visi[now.a][now.b][now.c]){
                visi[now.a][now.b][now.c] = 1;
                qu.push(now);
            }
            if(temp.a > c-temp.c){//fill c, a has water left
                now.a = temp.a - (c - temp.c);
                now.b = temp.b;
                now.c = c;
                now.times = temp.times+1;
            }else{//pour to c, a become empty
                now.a = 0;
                now.b = temp.b;
                now.c = temp.c + temp.a;
                now.times = temp.times+1;
            }
            //record status 
            if(!visi[now.a][now.b][now.c]){
                visi[now.a][now.b][now.c] = 1;
                qu.push(now);
            }
        }//a
        //b
        if(temp.b != 0 ){
            if(temp.b > a-temp.a){
                now.a = a;
                now.b = temp.b - (a-temp.a);
                now.c = temp.c;
                now.times = temp.times+1;
            }else{
                now.a = temp.a + temp.b;
                now.b = 0;
                now.c = temp.c;
                now.times = temp.times+1;
            }
            if(!visi[now.a][now.b][now.c]){
                visi[now.a][now.b][now.c] = 1;
                qu.push(now);
            }
            if(temp.b > c-temp.c){
                now.a = temp.a;
                now.b = temp.b - (c-temp.c);
                now.c = c;
                now.times = temp.times+1;
            }else{
                now.a = temp.a;
                now.b = 0;
                now.c = temp.c + temp.b;
                now.times = temp.times+1;
            }
            if(!visi[now.a][now.b][now.c]){
                visi[now.a][now.b][now.c] = 1;
                qu.push(now);
            }
        }//b
        //c
        if(temp.c != 0){
            if(temp.c > a-temp.a){
                now.a = a;
                now.b = temp.b;
                now.c = temp.c - (a-temp.a);
                now.times = temp.times+1;
            }else{
                now.a = temp.a + temp.c;
                now.b = temp.b;
                now.c = 0;
                now.times = temp.times+1;
            }
            if(!visi[now.a][now.b][now.c]){
                visi[now.a][now.b][now.c] = 1;
                qu.push(now);
            }
            if(temp.c > b-temp.b){
                now.a = temp.a;
                now.b = b;
                now.c = temp.c - (b-temp.b);
                now.times = temp.times+1;
            }else{
                now.a = temp.a;
                now.b = temp.b + temp.c;
                now.c = 0;
                now.times = temp.times+1;
            }
            if(!visi[now.a][now.b][now.c]){
                visi[now.a][now.b][now.c] = 1;
                qu.push(now);
            }
        }//c
    }//while
    if(qu.empty())
        printf("NO\n");
    else{
        //printf("test: %d %d %d\n", temp.a, temp.b, temp.c);
        printf("%d\n", temp.times);
    }
    return;
}

int main(){
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF && (a || b || c)){
        if(a&1)
            printf("NO\n");
        else
            bfs(a,b,c);
    }
    return 0;
}
