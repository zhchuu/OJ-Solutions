/*
 * POJ-1477
 * G++
 */
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 50+2;
int n, walls[maxn];

int main(){
    int kase=1;
    while(scanf("%d", &n) && n){
	int sum=0, ans=0;
	for(int i=0; i<n; i++){
	    scanf("%d", &walls[i]);
	    sum += walls[i];
	}
	int avg = sum / n;
	for(int i=0; i<n; i++)
	    ans += max(0, walls[i]-avg);
	printf("Set #%d\nThe minimum number of moves is %d.\n\n", kase++, ans);
    }//while
    return 0;
}
