/*
 * POJ-1716
 * G++
 */
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 10000+2;
int n;

struct node{
    int l, r;
    friend bool operator <(node a, node b){
	return a.r < b.r;
    }
}intervals[maxn];

int solve(){
    int ret = 2, first, second;
    first = intervals[0].r;
    second = intervals[0].r-1;
    for(int i=1; i<n; i++){
	if(intervals[i].l > first){
	    first = intervals[i].r;
	    second = intervals[i].r-1;
	    ret += 2;
	}else if(intervals[i].l <= first && intervals[i].l > second){
	    second = first;
	    first = intervals[i].r;
	    ret += 1;
	}else if(intervals[i].l <= second)
	    continue;
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
	scanf("%d %d", &intervals[i].l, &intervals[i].r);
    sort(intervals, intervals+n);
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}
