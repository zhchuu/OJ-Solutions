/*
 * Find the kth smallest element
 * Hint: Divide and conquer
 * */
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<time.h>
using namespace std;

const int maxn = 100+5;
const int N = 100;
int arr[maxn];

int select(int *A, int low, int high, int k){
    int qua = high - low + 1;
    if(qua < 44){
        sort(A+low, A+high+1);
        return A[k];
    }
    int gp = floor(qua / 5);
    int M[maxn];
    int idx = 0;
    for(int i=low; i<high; i+=5){
        sort(A+i, A+i+5);
        M[++idx] = A[i+2];
    }
    int mm = select(M, 1, gp, ceil(gp/2));
    int A1[maxn], A2[maxn], A3[maxn];
    int i1 = 0, i2 = 0, i3 = 0;
    for(int i=low; i<=high; i++){
        if(A[i] < mm)
            A1[++i1] = A[i];
        else if(A[i] == mm)
            A2[++i2] = A[i];
        else
            A3[++i3] = A[i];
    }
    if(i1 >= k)
        return select(A1, 1, i1, k);
    else if(i1 + i2 >= k)
        return mm;
    else if(i1 + i2 < k) 
        return select(A3, 1, i3, k-i1-i2);
    else
        return -1;
}

int main(){
    srand((unsigned)time(NULL));
    for(int i=1; i<=N; i++)
        arr[i] = rand() % 100;
    printf("Original:\n");
    for(int i=1; i<=N; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Kth:(K=6)\n");
    int ans = select(arr, 1, N, 6);
    printf("%d\n", ans);

    printf("Sorted:\n");
    sort(arr+1, arr+N+1);
    for(int i=1; i<=N; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
