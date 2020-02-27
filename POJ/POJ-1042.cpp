/*
 * POJ-1042
 * G++
 */
#include<stdio.h>
#include<memory>
#include<queue>
#include<math.h>
#include<string.h>
using namespace std;

const int maxn = 30;
struct node{
    int id;
    int f;
    int d;
    friend bool operator <(node a, node b){
	if(a.f == b.f) return a.id > b.id;
	return a.f < b.f;
    }
};
node lakes[maxn];
int t[maxn], cost[maxn][maxn];
int n, h;

void fishing(){
    int maxans = 0;
    int maxk = 1;
    for(int i=1; i<=n; i++){ // End the trip in lake i
	int cost_in_trip = 0;
	for(int j=1; j<i; j++) // Calculate the total cost in the trip
	    cost_in_trip += t[j];
	priority_queue<node> pq;
	for(int j=1; j<=i; j++)
	    pq.push(lakes[j]);

	int ans = 0;
	int left = h - cost_in_trip; // Time left
	for(int j=1; j<=left; j++){
	    node cur = pq.top();
	    ans += cur.f;
	    cost[i][cur.id] += 5;
	    pq.pop();
	    pq.push(node{cur.id, max(cur.f - cur.d, 0), cur.d});
	}
	if(maxans < ans){
	    maxans = ans;
	    maxk = i;
	}
    }//for
    for(int i=1; i<n; i++)
	printf("%d, ", cost[maxk][i]);
    printf("%d\n", cost[maxk][n]);
    printf("Number of fish expected: %d\n\n", maxans);
}

int main(){
    while(scanf("%d", &n) != EOF && n){
	scanf("%d", &h);
	h = h * 12; // 1hours = 5mins * 12
	memset(cost, 0, sizeof(cost));

	for(int i=1; i<=n; i++){
	    scanf("%d", &lakes[i].f);
	    lakes[i].id = i;
	}
	for(int i=1; i<=n; i++)
	    scanf("%d", &lakes[i].d);
	for(int i=1; i<=n-1; i++)
	    scanf("%d", &t[i]);
	fishing();
    }//while

    return 0;
}
