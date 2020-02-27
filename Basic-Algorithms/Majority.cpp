/*
 * Finding the majority element if exists
 * Hint: Recursion
 * If two different elements in the original sequence are removed, 
 * then the majority in the original sequence remains the majority in the new sequence.
 * */
#include<stdio.h>
#include<algorithm>
#include<time.h>
#include<stdlib.h>

const int maxn = 5;
int arr[maxn];

int candidate(int start){
    int idx = start+1, c = arr[start], cnt = 1;
    while(idx < maxn && cnt > 0){
        if(arr[idx] == c)
            cnt += 1;
        else
            cnt -= 1;
        idx += 1;
    }
    if(idx == maxn)
        return c;
    return candidate(idx);
}

int majority(){
    int c = candidate(0), cnt = 0;
    for(int i=0; i<maxn; i++){
        if(arr[i] == c)
            cnt += 1;
    }
    if(cnt > maxn/2)
        return c;
    return -1;
}

int main(){
    srand((unsigned)time(NULL));
    for(int i=0; i<maxn; i++)
        arr[i] = rand() % 5;
    printf("Original:\n");
    for(int i=0; i<maxn; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Majority:\n");
    int ans = majority();
    if(ans == -1)
        printf("none\n");
    else
        printf("%d\n", ans);
    return 0;
}
