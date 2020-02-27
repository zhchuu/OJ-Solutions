/*
 * POJ-1797
 */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1000 + 5;
int maxdis[maxn], maxnode[maxn], map[maxn][maxn], kase, n, m;
bool vis[maxn];

int main(){
	int from, to, dis;
	cin>>kase;
	for(int k=1; k<=kase; k++){
		for(int i=0; i<maxn; i++)
			for(int j=0; j<maxn; j++)
				map[i][j] = -INF;
		memset(vis, 0, sizeof(vis));
		//input
		cin>>n>>m;
		for(int i=0; i<m; i++){
			cin>>from>>to>>dis;
			map[from][to] = dis;
			map[to][from] = dis;
		}//for
		// select 1 to set
		for(int i=1; i<=n; i++){
			maxdis[i] = map[1][i];
			maxnode[i] = 1;
		}
		maxdis[1] = 0;
		vis[1] = 1;
		int ans = INF;
		for(int i=1; i<n; i++){// (n-1) times selection
			int max = -INF;
			int node;
			// choose a farest node
			for(int j=1; j<=n; j++){
				if(!vis[j] && max < maxdis[j]){
					max = maxdis[j];
					node = j;
				}
			}//for
			if(ans > max)
				ans = max;
			vis[node] = 1;
			if(node == n)
				break;
			for(int j=1; j<=n; j++){
				if(!vis[j] && map[node][j] > maxdis[j]){
					maxdis[j] = map[node][j];
					maxnode[j] = node;
				}//if
			}//for
		}//for
		cout<<"Scenario #"<<k<<":"<<endl; // Important!!! Forgotting ":" causes numbers of WA.
		printf("%d\n\n", ans);
	}//for
	return 0;
}
