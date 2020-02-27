/*
 * HDU-1009
 */
#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 5;
int m, n;

struct node{
    int bean;
    int food;
    double cost; // beans per food
}barn[maxn];

bool cmp(const node &a, const node &b){
    return a.cost > b.cost;
}

int main(){
    while(scanf("%d %d", &m, &n) && m != -1 && n != -1){
	for(int i=0; i<n; i++){
	    scanf("%d %d", &barn[i].bean, &barn[i].food);
	    barn[i].cost = barn[i].bean*1.0 / barn[i].food;
	}//for
	sort(barn, barn+n, cmp);

	int left = m;
	double ans = 0.0;
	for(int i=0; i<n; i++){
	    if(left >= barn[i].food){  //enough
		ans += barn[i].bean*1.0;
		left -= barn[i].food;
	    }else{
		ans += left * barn[i].cost;
		left = 0;
	    }
	    if(left <= 0)
		break;
	}
	printf("%.3lf\n", ans);
    }//while
    
    return 0;
}
