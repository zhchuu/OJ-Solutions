/*
 * POJ-3414
 */
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;

struct node{
	int a, b, step;
	string op;
	// 0 -> "FILL(1)"
	// 1 -> "FILL(2)"
	// 2 -> "DROP(1)"
	// 3 -> "DROP(2)"
	// 4 -> "POUR(1,2)"
	// 5 -> "POUR(2,1)"
}strt, tmp, nxt;

const int maxn = 100 + 5;
bool vis[maxn][maxn];
queue<node> q;
int A, B, C, K;
string ops;

void bfs(){
	strt.a = 0;
	strt.b = 0;
	strt.step = 0;
	strt.op = "";
	q.push(strt);
	vis[0][0] = true;
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		if(tmp.a == C || tmp.b == C){// Reach target
			K = tmp.step;
			ops = tmp.op;
			return;
		}
		// Six operations
		// FILL(1)
		nxt.a = A;
		nxt.b = tmp.b;
		nxt.step = tmp.step + 1;
		nxt.op = tmp.op + '0';
		if(!vis[nxt.a][nxt.b]){
			vis[nxt.a][nxt.b] = true;
			q.push(nxt);
		}
		// FILL(2)
		nxt.a = tmp.a;
		nxt.b = B;
		nxt.step = tmp.step + 1;
		nxt.op = tmp.op + '1';
		if(!vis[nxt.a][nxt.b]){
			vis[nxt.a][nxt.b] = true;
			q.push(nxt);
		}
		// DROP(1)
		nxt.a = 0;
		nxt.b = tmp.b;
		nxt.step = tmp.step + 1;
		nxt.op = tmp.op + '2';
		if(!vis[nxt.a][nxt.b]){
			vis[nxt.a][nxt.b] = true;
			q.push(nxt);
		}
		// DROP(2)
		nxt.a = tmp.a;
		nxt.b = 0;
		nxt.step = tmp.step + 1;
		nxt.op = tmp.op + '3';
		if(!vis[nxt.a][nxt.b]){
			vis[nxt.a][nxt.b] = true;
			q.push(nxt);
		}
		// POUR(1,2)
		nxt.a = max(0, tmp.a - (B-tmp.b));
		nxt.b = min(B, tmp.b + tmp.a);
		nxt.step = tmp.step + 1;
		nxt.op = tmp.op + '4';
		if(!vis[nxt.a][nxt.b]){
			vis[nxt.a][nxt.b]= true;
			q.push(nxt);
		}
		// POUR(2,1)
		nxt.a = min(A, tmp.a + tmp.b);
		nxt.b = max(0, tmp.b - (A-tmp.a));
		nxt.step = tmp.step + 1;
		nxt.op = tmp.op + '5';
		if(!vis[nxt.a][nxt.b]){
			vis[nxt.a][nxt.b] = true;
			q.push(nxt);
		}
	}//while
	return;
}

int main(){
	while(~scanf("%d %d %d", &A, &B, &C)){
		memset(vis, 0, sizeof(vis));
		while(!q.empty())
			q.pop();
		K = -1;
		bfs();
		if(K == -1){
			printf("impossible\n");
			continue;
		}
		printf("%d\n", K);
		for(int i=0; i<ops.size(); i++){
			char c = ops[i];
			if(c == '0')
				printf("FILL(1)\n");
			else if(c == '1')
				printf("FILL(2)\n");
			else if(c == '2')
				printf("DROP(1)\n");
			else if(c == '3')
				printf("DROP(2)\n");
			else if(c == '4')
				printf("POUR(1,2)\n");
			else if(c == '5')
				printf("POUR(2,1)\n");
		}
	}
	return 0;
}
