/*
 * POJ-1323
 * G++
 */
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;

const int maxn = 50+2;
const int maxm = 20+2;

int vis[maxn*maxm], my_cards[maxn];
int n, m;

int solve(){
    int ret = 0, max_pos = 0;
    sort(my_cards, my_cards+n, greater<int>());
    for(int i=n*m; i>0; i--){
	if(vis[i] == 0){
	    max_pos++;
	    if(max_pos >= n)
		break;
	}
	else if(i == my_cards[max_pos]){
	    ret++;
	    max_pos++;
	}
    }//for
    return ret;
}

int main(){
    int kase = 1;
    while(scanf("%d %d", &m, &n) && m && n){
	memset(vis, 0, sizeof(vis));
	memset(my_cards, 0, sizeof(my_cards));
	for(int i=0; i<n; i++){
	    scanf("%d", &my_cards[i]);
	    vis[my_cards[i]] = 1;
	}
	int ans = solve();
	printf("Case %d: %d\n", kase++, ans);
    }//while
    return 0;
}
