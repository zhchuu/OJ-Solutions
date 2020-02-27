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
int num;

int main(){
    int len;
    while(scanf("%d", &len) && len){
        int cnt = 0;
        int maxSum = -1, sum = 0, x, y, begin, end, head, tail;
        for(int i=0; i<len; i++){
            scanf("%d", &num);
            if(i==0){
                head = num;
                x = head;
            }
            if(i==len-1)
                tail = num;
            if(num < 0)
                cnt += 1;
            sum += num;
            if(sum >= num)
                y = num;
            else{
                x = num;
                y = num;
                sum = num;
            }
            if(sum > maxSum){
                maxSum = sum;
                begin = x;
                end = y;
            }
        }//for
        if(cnt == len)
            printf("0 %d %d\n", head , tail);
        else
            printf("%d %d %d\n", maxSum, begin, end);
    }//while
    return 0;
}
