/*
 * HDU-1231
 * Hint: dp
 * */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn = 10000+5;
int num[maxn];

int main(){
    int len;
    while(scanf("%d", &len) && len){
        int cnt = 0;
        for(int i=0; i<len; i++){
            scanf("%d", &num[i]);
            if(num[i] < 0)
                cnt += 1;
        }
        if(cnt == len){
            printf("0 %d %d\n", num[0] , num[len-1]);
            continue;
        }
        int maxSum = -1, sum = 0, x = 0, y = 0, begin, end;
        for(int i=0; i<len; i++){
            sum += num[i];
            if(sum >= num[i])
                y = i;
            else{
                x = i;
                y = i;
                sum = num[i];
            }
            if(sum > maxSum){
                maxSum = sum;
                begin = x;
                end = y;
            }
        }
        printf("%d %d %d\n", maxSum, num[begin], num[end]);
    }//while
    return 0;
}
