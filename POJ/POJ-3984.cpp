/*
 * POJ-3984
 * G++
 */
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

struct node{
	int x, y;
	string path;
}strt, tmp, nxt;

const int maxn = 5;
int maze[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char go[4] = {'d', 'u', 'r', 'l'};
queue<node> q;

string bfs(){
	strt.x = 0;
	strt.y = 0;
	strt.path = "";
	q.push(strt);
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		if(tmp.x == 4 && tmp.y == 4)
			return tmp.path;
		for(int i=0; i<4; i++){
			nxt.x = tmp.x + dir[i][0];
			nxt.y = tmp.y + dir[i][1];
			if(nxt.x < 0 || nxt.x > 4 || nxt.y < 0 || nxt.y > 4 || vis[nxt.x][nxt.y] || maze[nxt.x][nxt.y])
				continue;
			vis[nxt.x][nxt.y] = true;
			nxt.path = tmp.path + go[i];
			q.push(nxt);
		}//for
	}//while
	return "";
}

int main(){
	for(int i=0; i<maxn; i++)
		for(int j=0; j<maxn; j++)
			scanf("%d", &maze[i][j]);
	//init
	memset(vis, 0, sizeof(vis));
	while(!q.empty())
		q.pop();
	string ans = bfs();
	int x = 0, y = 0;
	printf("(%d, %d)\n", x, y);
	for(int i=0; i<ans.size(); i++){
		switch(ans[i]){
		case 'u':x = x - 1;break;
		case 'd':x = x + 1;break;
		case 'l':y = y - 1;break;
		case 'r':y = y + 1;break;
		default:break;
		}
		printf("(%d, %d)\n", x, y);
	}
	return 0;
}
