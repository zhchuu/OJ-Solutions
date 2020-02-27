#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn = 15+2;
bool map[maxn][maxn];
bool cur[maxn][maxn];
bool res[maxn][maxn];
int dir[5][2] = { {-1, 0}, {1, 0}, {0, 0}, {0, -1}, {0, 1}};
int ans = INF;
int n, m;

bool getColor(int x, int y){
	int res = map[x][y];
	for(int i=0; i<5; i++){
		int fx = x + dir[i][0];
		int fy = y + dir[i][1];
		if(fx >=1 && fx <=n && fy >=1 && fy <= m)
			res += cur[fx][fy];
	}
	return res%2;
}

int work(){
	int ret = 0;
	// From second row
	for(int i=2; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(getColor(i-1, j))
				cur[i][j] = 1;
	// Check last row
	for(int i=1; i<=m; i++)
		if(getColor(n, i))
			return INF;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			ret += cur[i][j];
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d", &map[i][j]);
	for(int s=0; s < 1<<m; s++){
		memset(cur, 0, sizeof(cur));
		for(int i=1; i<=m; i++)
			cur[1][i] = s >> (m - i) & 1;
		int t = work();
		if(t < ans){
			ans = t;
			memcpy(res, cur, sizeof(cur));
		}
	}
	if(ans == INF)
		printf("IMPOSSIBLE\n");
	else{
		for(int i=1; i<=n; i++){
			for(int j=1; j<m; j++)
				printf("%d ", res[i][j]);
			printf("%d\n", res[i][m]);
		}
	}
	return 0;
}
