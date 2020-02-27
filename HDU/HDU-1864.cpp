/*
 * HDU-1864
 * Hint: dp
 * */
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn = 3000000+5;
const int N = 30+5;
int dp[maxn], money[N], n, a, b, c, most, idx;
double q, price;

void work(){
    for(int i=1; i<=idx; i++)
        for(int j=most; j>=money[i]; j--)
            dp[j] = max(dp[j], dp[j-money[i]]+money[i]);
}

int main(){
    while(~scanf("%lf%d", &q, &n) && n){
        char type;
        int cnt;
        memset(dp, 0, sizeof(dp));
        memset(money, 0, sizeof(money));
        idx = 0;
        for(int i=0; i<n; i++){
            scanf("%d", &cnt);
            a = b = c = 0;
            most = (int)(q*100);
            bool illegal = false;
            for(int j=0; j<cnt; j++){
                scanf("%*c%c:%lf", &type, &price);
                int tmp = (int)(price*100);
                if(type == 'A')
                    a += tmp;
                else if(type == 'B')
                    b += tmp;
                else if(type == 'C')
                    c += tmp;
                else
                    illegal = true;
            }//for
            if(!illegal && a+b+c<=100000 && a<=60000 && b<=60000 && c<=60000)
                money[++idx] = a+b+c;
        }//for
        work();
        printf("%.2lf\n", dp[most]/100.0);
    }//while
    return 0;
}
