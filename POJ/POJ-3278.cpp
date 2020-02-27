/*
 * POJ-3278
 */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;

struct node{
	int x, step;
	bool operator < (node a) const {return step < a.step;}
	bool operator > (node a) const {return step > a.step;}
}strt, tmp, nxt;

const int maxn = 100000+5;
priority_queue<node, vector<node>, greater<node>> pq;
bool vis[maxn];
int N, K;

int bfs(){
	strt.x = N;
	strt.step = 0;
	pq.push(strt);
	while(!pq.empty()){
		tmp = pq.top();
		pq.pop();
		if(tmp.x == K)
			return tmp.step;
		// Move forward
		nxt.x = tmp.x + 1;
		nxt.step = tmp.step + 1;
		if(nxt.x >= 0 && nxt.x <= 100000 && !vis[nxt.x]){
			vis[nxt.x] = true;
			pq.push(nxt);
		}
		// Move back
		nxt.x = tmp.x - 1;
		nxt.step = tmp.step + 1;
		if(nxt.x >= 0 && nxt.x <= 100000 && !vis[nxt.x]){
			vis[nxt.x] = true;
			pq.push(nxt);
		}
		// Teleport
		nxt.x = tmp.x * 2;
		nxt.step = tmp.step + 1;
		if(nxt.x >= 0 && nxt.x <= 100000 && !vis[nxt.x]){
			vis[nxt.x] = true;
			pq.push(nxt);
		}
	}//while
	return -1;
}

int main(){
	scanf("%d %d", &N, &K);

	memset(vis, 0, sizeof(vis));
	while(!pq.empty())
		pq.pop();
	int ans = bfs();
	printf("%d\n", ans);
	return 0;
}
