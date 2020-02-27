/*
 * POJ-3126
 */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int num;
	int step;
	bool operator < (node a) const {return step < a.step;}
	bool operator > (node a) const {return step > a.step;}
}strt, nxt, tmp;

const int maxn = 10000+10;
int kase, from, to;
priority_queue<node, vector<node>, greater<node>> pq;
bool prime[maxn];
bool vis[maxn];

void work(){ // important
	memset(prime, 1, sizeof(prime));
	for(int i=2; i<9999/2; i++)
		for(int j=2; j<=9999/i; j++)
			prime[i*j] = 0;
}

bool isPrime(int num){
	return prime[num];
}

int change(int org, int pos, int k){
	int num[4];
	for(int i=3; i>=0; i--){
		num[i] = org%10;
		org /= 10;
	}
	num[pos] = k;
	int ret = num[0]*1000 + num[1]*100 + num[2]*10 + num[3];
	return ret;
}

int bfs(){
	strt.num = from;
	strt.step = 0;
	pq.push(strt);
	while(!pq.empty()){
		tmp = pq.top();
		pq.pop();
		if(tmp.num == to)
			return tmp.step;
		// Change four digits
		for(int i=0; i<=9; i++){
			for(int j=0; j<4; j++){
				if(i == 0 && j == 0)
					continue;
				int newnum = change(tmp.num, j, i);
				if(!isPrime(newnum) || vis[newnum])
					continue;
				nxt.num = newnum;
				nxt.step = tmp.step + 1;
				vis[newnum] = true;
				pq.push(nxt);
			}
		}//for
	}
	return -1;
}

int main(){
	work();
	scanf("%d", &kase);
	while(kase--){
		scanf("%d %d", &from, &to);
		while(!pq.empty())
			pq.pop();
		memset(vis, 0, sizeof(vis));
		vis[from] = true;
		int ans = bfs();
		if(ans == -1)
			printf("Impossible\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
