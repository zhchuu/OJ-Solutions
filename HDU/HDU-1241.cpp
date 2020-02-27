/*
 * HDU-1241
 */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;
char map[maxn][maxn];
bool vis[maxn][maxn];
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
int m, n, cnt;

void dfs(int x, int y){
	int nx, ny;
	vis[x][y] = true;
	for(int i=0; i<8; i++){
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if(nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny] || map[nx][ny] == '*')
			continue;
		dfs(nx, ny);
	}
	return;
}

int main(){
	while(scanf("%d %d", &m, &n) && m && n){
		//input
		for(int i=0; i<m; i++)
			scanf("%s", map[i]);
		//init
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		//solve
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(map[i][j] == '*' || vis[i][j])
					continue;
				dfs(i, j);
				cnt += 1;
			}//for
		}//for
		printf("%d\n", cnt);
	}//while
	return 0;
}
