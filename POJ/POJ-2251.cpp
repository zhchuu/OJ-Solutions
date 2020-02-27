/*
 * POJ-2251
 */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;

struct node{
	int l, r, c, step;
	bool operator < (node a) const {return step < a.step;}
	bool operator > (node a) const {return step > a.step;}
}strt, nxt, tmp;

const int maxn = 30 + 2;
char map[maxn][maxn][maxn];// L R C
bool vis[maxn][maxn][maxn];
int L, C, R, end_l, end_r, end_c, beg_l, beg_r, beg_c;
priority_queue<node, vector<node>, greater<node>> pq;
int mov[6][3] = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

int bfs(){
	strt.l = beg_l;
	strt.r = beg_r;
	strt.c = beg_c;
	strt.step = 0;
	pq.push(strt);
	while(!pq.empty()){
		tmp = pq.top();
		pq.pop();
		if(tmp.l == end_l && tmp.r == end_r && tmp.c == end_c)
			return tmp.step;
		for(int i=0; i<6; i++){
			nxt.l = tmp.l + mov[i][0];
			nxt.r = tmp.r + mov[i][1];
			nxt.c = tmp.c + mov[i][2];
			nxt.step = tmp.step + 1;
			if(nxt.l >= L || nxt.r >= R || nxt.c >= C || nxt.l < 0 || nxt.r < 0 || nxt.c < 0 ||
			   vis[nxt.l][nxt.r][nxt.c] || map[nxt.l][nxt.r][nxt.c] == '#')
				continue;
			vis[nxt.l][nxt.r][nxt.c] = true;
			pq.push(nxt);
		}
	}//while
	return -1;
	}

int main(){
	while(scanf("%d %d %d", &L, &R, &C) && L!=0 && R!=0 && C!=0){
		for(int i=0; i<L; i++){
			for(int j=0; j<R; j++){
				scanf("%s", map[i][j]);
				for(int k=0; k<C; k++){
					if(map[i][j][k] == 'S'){
						beg_l = i;
						beg_r = j;
						beg_c = k;
					}
					else if(map[i][j][k] == 'E'){
						end_l = i;
						end_r = j;
						end_c = k;
					}
				}//for C
			}//for R
		}//for L

		memset(vis, 0, sizeof(vis));
		while(!pq.empty())
			pq.pop();

		vis[beg_l][beg_r][beg_c] = true;
		int res = bfs();
		if(res == -1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n", res);
	}//while
	return 0;
}
