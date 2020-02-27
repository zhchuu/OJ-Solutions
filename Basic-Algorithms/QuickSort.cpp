/*
 * Quick sort
 * Hint: Divide and conquer
 * */
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 20;
int arr[maxn];

int partition(int *A, int low, int high){
    int pivot = A[high];//Several ways to choose pivot:
                        // 1) Always pick the first element
                        // 2) Always pick the last element
                        // 3) Pick a random element
                        // 4) Pick median element
    int i = low - 1;//index i point to the last number which is smaller than privot
                    //so A[low...i] are the number smaller than pivot
                    //A[i+1...high] are the number larger than pivot
    for(int j=low; j<=high-1; j++){
        if(A[j] <= pivot){
            i += 1;
            if(i != j)
                swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[high]);//swap A[i+1] and A[high] making i+1 be the middle position
    return i+1;
}

void quickSort(int *A, int low, int high){
    if(low < high){
        int pi = partition(A, low, high);//pi is in a right position now
        quickSort(A, low, pi-1);
        quickSort(A, pi+1, high);
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
    quickSort(arr, 0, maxn-1);
    for(int i=0; i<maxn; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
