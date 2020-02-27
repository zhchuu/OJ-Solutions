/*
 * POJ-1006
 * Hint: Chinese Reminder Theory
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
    int A, B, C, p, e, i, d, kase = 1;
    for(int k=1; (28*33*k)%23 != 1; k++)
        A = 28*33*(k+1);
    for(int k=1; (23*33*k)%28 != 1; k++)
        B = 23*33*(k+1);
    for(int k=1; (23*28*k)%33 != 1; k++)
        C = 23*28*(k+1);
    while(~scanf("%d %d %d %d", &p, &e, &i, &d)){
        if(p == -1 && e == -1 && i == -1 && d == -1)
            break;
        int ans = A*p + B*e + C*i;
        ans = ans % 21252 - d;
        if(ans <= 0)
            ans += 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n", kase++, ans);

    }
    return 0;
}
