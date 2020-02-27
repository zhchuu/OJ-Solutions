/*
 * POJ-1065
 * G++
 */
#include<stdio.h>
#include<string.h>
#include<memory>
#include<algorithm>
using namespace std;

const int INF = 10000+10;
const int maxn = 5000+5;
struct node{
    int length;
    int weight;
    friend bool operator <(node a, node b){
	if(a.length == b.length)
	    return a.weight < b.weight;
	return a.length < b.length;
    }
};
node sticks[maxn];
int vis[maxn];

int main(){
    int kase, n;
    scanf("%d", &kase);
    while(kase--){
	memset(vis, 0, sizeof(vis));
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	    scanf("%d %d", &sticks[i].length, &sticks[i].weight);
	sort(sticks, sticks+n);

	int ans = 0, pre_len = INF, pre_wet = INF;
	for(int i=0; i<n; i++){
	    if(vis[i])
		continue;
	    ans += 1;
	    vis[i] = 1;
	    pre_len = sticks[i].length;
	    pre_wet = sticks[i].weight;
	    for(int j=i+1; j<n; j++){
		if(!vis[j] && sticks[j].length >= pre_len && sticks[j].weight >= pre_wet){
		    vis[j] = 1;
		    pre_len = sticks[j].length;
		    pre_wet = sticks[j].weight;
		}
	    }//for
	}//for
	printf("%d\n", ans);
    }//while

    return 0;
}
