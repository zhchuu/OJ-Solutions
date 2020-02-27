/*
 * POJ-2387
 * Hint: dijkstra
 */
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<memory.h>
#include<math.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1000+5;
int map[maxn][maxn];
int dis[maxn];// from start to i
int pre[maxn];
int T, N;

void init(){
	for(int i=0; i<maxn; i++)
		for(int j=0; j<maxn; j++)
			map[i][j] = INF;
}

void Dijkstra(int v0){
	bool s[maxn];
	for(int i=1; i<=N; i++){
		dis[i] = map[v0][i];
		s[i] = false;
		if(dis[i] == INF)
			pre[i] = -1;
		else
			pre[i] = v0;
	}//for
	dis[v0] = 0;
	s[v0] = true;
	for(int i=2; i<=N; i++){
		int mindis = INF;
		int u = v0;
		for(int j=1; j<=N; j++){
			if(!s[j] && dis[j] < mindis){
				u = j;
				mindis = dis[j];
			}
		}//for
		s[u] = true;
		for(int j=1; j<=N; j++){
			if(!s[j] && map[u][j] < INF){
				if(dis[u] + map[u][j] < dis[j]){
					dis[j] = dis[u] + map[u][j];
					pre[j] = u;
				}//if
			}//if
		}//for
	}//for
}

int main(){
	while(~scanf("%d %d", &T, &N)){
		init();
		//input
		int from, to, len;
		for(int i=0; i<T; i++){
			scanf("%d %d %d", &from, &to, &len);
			map[from][to] = len < map[from][to] ? len : map[from][to];
			map[to][from] = map[from][to];
		}
		//solve
		Dijkstra(N);
		printf("%d\n", dis[1]);
	}//while
	return 0;
}
