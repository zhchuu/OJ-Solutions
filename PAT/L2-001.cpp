/*
 * PAT L2-001
 * Dijkstra, record value while searching
 * */

#include<stdio.h>
#include<algorithm>
using namespace std;

int const MAX = 500+5;
int const INF =0x3fffffff;
int mp[MAX][MAX], val[MAX], path[MAX], dis[MAX], totval[MAX], pathnum[MAX];
//dis[i] means the mimimum distance from start to i
bool vis[MAX];
int cities, paths, start, destin;

void Dijkstra(int start){
	for(int i=0;i<cities;i++)//Initialize all distance
		dis[i] = INF;
	vis[start] = true;
	dis[start] = 0;
	totval[start] = val[start];
	pathnum[start] = 1;
	for(int i=0;i<cities;i++){//Initialize the path that is next to start
		if(mp[start][i] != INF && i != start){
			dis[i] = mp[start][i];
			path[i] = start;
			totval[i] = val[start] + val[i];
			pathnum[i] = 1;
		}//if
	}//for

	for(int i=0;i<cities-1;i++){//There are n-1 cities left
		int mi = INF, trans = start;
		for(int j=0;j<cities;j++){//Find the mimimum value from cities that haven't been selected
			if(!vis[j] && dis[j] < mi){
				mi = dis[j];
				trans = j;
			}//if
		}//for
		vis[trans] = true;
		for(int j=0;j<cities;j++){
			if(!vis[j]){
				if(dis[trans] + mp[trans][j] < dis[j]){
					pathnum[j] = pathnum[trans];
					dis[j] = dis[trans] + mp[trans][j];
					totval[j] = totval[trans] + val[j];
					path[j] = trans;
				}else if(dis[trans] + mp[trans][j] == dis[j]){
					pathnum[j] += pathnum[trans];
					if(totval[j] < totval[trans] + val[j]){
						totval[j] = totval[trans] + val[j];
						path[j] = trans;
					}
				}
			}
		}//for
	}//for
}

int main(){
	scanf("%d %d %d %d", &cities, &paths, &start, &destin);
	for(int i=0;i<cities;i++)
		scanf("%d", &val[i]);
	for(int i=0;i<cities;i++)
		for(int j=0;j<cities;j++)
			mp[i][j] = INF;
	int x,y,d;
	for(int i=0;i<paths;i++){
		scanf("%d %d %d", &x,&y,&d);
		mp[x][y] = min(mp[x][y], d);
		mp[y][x] = mp[x][y];
	}
	Dijkstra(start);
	int ans[MAX];
	int idx=0,cur=destin;
	while(cur != start){
		ans[idx++] = cur;
		cur = path[cur];
	}
	ans[idx] = start;
	printf("%d %d\n", pathnum[destin], totval[destin]);
	for(int i=idx;i>0;i--)
		printf("%d ",ans[i]);
	printf("%d\n",ans[0]);
	return 0;

}
