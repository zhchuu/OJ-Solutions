/*
 * TimSort
 */
#include<bits/stdc++.h>
using namespace std;
const int RUN = 32;
const int maxn = 200;
int arr[maxn];

// Sorts array from left to right which is of size atmost RUN
void insertionSort(int arr[], int left, int right){
    for(int i=left+1; i<=right; i++){
	int temp = arr[i];
	int j = i - 1;
	while(arr[j] > temp && j>= left){
	    arr[j+1] = arr[j];
	    j--;
	}
	arr[j+1] = temp;
    }
}

// Merges sorted runs
void merge(int arr[], int l, int m, int r){
    // from l to m+1, m to r
    int len1 = m-l+1, len2 = r - m;
    int left[len1], right[len2];
    for(int i=0; i<len1; i++)
	left[i] = arr[l+i];
    for(int i=0; i<len2; i++)
	right[i] = arr[m+1+i];

    int i = 0;
    int j = 0;
    int k = l;

    while(i<len1 && j<len2){
	if(left[i] <= right[j])
	    arr[k++] = left[i++];
	else
	    arr[k++] = right[j++];
    }

    while(i < len1)
	arr[k++] = left[i++];
    while(j < len2)
	arr[k++] = right[j++];
}

// Iterative funciton to sort array[0...n-1]
void timSort(int arr[], int n){
    // sort individual chunks of size RUN
    for(int i=0; i<n; i+=RUN)
	insertionSort(arr, i, min((i+31), (n-1)));

    for(int size=RUN; size<n; size=2*size){
	for(int left=0; left<n; left+=2*size){
	    int mid = left + size - 1;
	    int right = min((left + 2*size - 1), (n - 1));

	    merge(arr, left, mid, right);
	}
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
	printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    srand((unsigned)time(NULL));

    for(int i=0; i<maxn; i++)
	arr[i] = rand() % 100;

    printf("Original:\n");
    printArray(arr, maxn);

    timSort(arr, maxn);

    printf("Sorted:\n");
    printArray(arr, maxn);

    return 0;
}
