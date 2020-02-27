/*
 * Generate all permutations
 * Hint: Recursion
 * */
#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 3;
int arr[maxn];

void output(){
    for(int i=0; i<maxn; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void perm1(int m){
    if(m == maxn-1)
        output();
    else{
        for(int j=m; j<maxn; j++){
            swap(arr[j], arr[m]);
            perm1(m+1);
            swap(arr[j], arr[m]);
        }
    }
}

void perm2(int m){
    if(m == 0)
        output();
    else{
        for(int j=0; j<maxn; j++){
            if(arr[j] == 0){
                arr[j] = m;
                perm2(m-1);
                arr[j] = 0;
            }
        }
    }
}

int main(){
    printf("Perm1:\n");
    for(int i=0; i<maxn; i++)
        arr[i] = i+1;
    perm1(0);
    printf("\nPerm2:\n");
    for(int i=0; i<maxn; i++)
        arr[i] = 0;
    perm2(maxn);
}
