/*
 * Bottom-up merge sort
 * */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>

const int maxn = 20;
int arr[maxn];

/*
 * Merge A[l...m] and A[m+1...r]
 * */
void merge(int *A, int l, int m, int r){
    int B[maxn];
    int s = l, t = m+1, k = l;
    while(s <= m && t<= r){
        if(A[s] <= A[t])
            B[k++] = A[s++];
        else
            B[k++] = A[t++];
    }
    if(s == m+1){
        while(t <= r)
            B[k++] = A[t++];
    }else{
        while(s <= m)
            B[k++] = A[s++];
    }
    for(int i=l; i<=r; i++)
        A[i] = B[i];
}
/*
 * Sort from A[0] to A[n-1]
 * */
void bottomUpSort(int *A, int n){
    int t = 1, s, i;
    while(t < n){
        s = t; t = 2*s; i = -1;
        while(i + t < n){
            merge(A, i+1, i+s, i+t);
            i = i+t;
        }
        if(i+s < n)
            merge(A, i+1, i+s, n-1);
    }
}

int main(){
    srand((unsigned)time(NULL));
    for(int i=0; i<maxn; i++)
        arr[i] = rand() % 100;
    printf("Original:\n");
    for(int i=0; i<maxn; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Sorted:\n");
    bottomUpSort(arr, 20);
    for(int i=0; i<maxn; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
