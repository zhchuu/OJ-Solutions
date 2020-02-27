#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 200+5;
double map[maxn][maxn];
pair<int, int> coord[maxn];
// mindis[i] indicates the smallest distance from i to selected set
// minnode[i] indicates the nearest node of i to selected set
double mindis[maxn], minnode[maxn];
int n;

int main(){
	int kase = 1;
	while(cin>>n && n){
		memset(mindis, 0, sizeof(mindis));
		for(int i=0; i<n; i++)
			cin >> coord[i].first >> coord[i].second;
		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			map[i][j] = 1.0*sqrt(pow(1.0*abs(coord[i].first-coord[j].first), 2) + pow(1.0*(abs(coord[i].second-coord[j].second)), 2));

		double ans = 0;
		// select 0 to set
		for(int i=0; i<n; i++){
			mindis[i] = map[0][i];
			minnode[i] = 0;
		}
		for(int i=0; i<n-1; i++){
			double min = INF; // smallest distance
			int node; // nearest node
			for(int j=0; j<n; j++){
				if(mindis[j] && min > mindis[j]){
					min = mindis[j];
					node = j;
				}//if
			}//for
			if(ans < min)
				ans = min;
			mindis[node] = 0.0; // select it into set
			if(node == 1)
				break;
			for(int j=0; j<n; j++){ // update all distance
				if(map[j][node] < mindis[j]){ // now node is one of the set
					mindis[j] = map[j][node];
					minnode[j] = node;
				}//if
			}//for
		}//for
		cout<<"Scenario #"<<kase++<<endl;
		printf("Frog Distance = %.3f\n\n", ans);
	}//while
	return 0;
}
