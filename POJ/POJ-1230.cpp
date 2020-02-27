/*
 * POJ-1230
 * G++
 */
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 100+5;
struct node{
    int x0, y0, x1, y1;
}walls[maxn];
int kase, n, k, vis[maxn];

int solve(){
    int ret = 0;
    for(int i=0; i<maxn; i++){
	if(vis[i] <= k)
	    continue;
	int maxlen = 0, which = 0;
	for(int j=0; j<maxn; j++){
	    int l = min(walls[j].y0, walls[j].y1);
	    int r = max(walls[j].y0, walls[j].y1);
	    if(l<=i && i<=r && r-i >= maxlen){
		maxlen = r-i;
		which = j;
	    }
	}//for
	int l = min(walls[which].y0, walls[which].y1);
	int r = max(walls[which].y0, walls[which].y1);
	walls[which].y0 = -1;
	walls[which].y1 = -1;
	for(int p=l; p<=r; p++)
	    vis[p] -= 1;
	ret += 1;
	i -= 1; // Go back and check this column again. Because there may be more than one wall should be deleted.
    }//for
    return ret;
}

int main(){
    scanf("%d", &kase);
    while(kase--){
	memset(walls, 0, sizeof(walls));
	memset(vis, 0, sizeof(vis));
	scanf("%d %d", &n, &k);
	for(int j=0; j<n; j++){
	    scanf("%d %d %d %d", &walls[j].y0, &walls[j].x0, &walls[j].y1, &walls[j].x1);
	    int l = min(walls[j].y0, walls[j].y1);
	    int r = max(walls[j].y0, walls[j].y1);
	    for(int p=l; p<=r; p++)
		vis[p] += 1;
	}//for
	int ans = solve();
	printf("%d\n", ans);
    }//for
    return 0;
}
