/*
 * POJ-2236
 * */
#include<stdio.h>
#include<math.h>
#include<memory.h>
#include<algorithm>
using namespace std;

struct node{
    int x, y;
};

const int maxn = 1001+2;
const int maxa = 1001*1001+2;
int n, d, num[maxa];
node com[maxn];
bool repaired[maxa];


void init(){
    for(int i=0; i<maxa; i++)
        num[i] = i;
    memset(repaired, 0, sizeof(repaired));
}

double sq(double n){
    return n*n;
}

int find(int a){
    if(num[a] == a)
        return a;
    return (num[a] = find(num[a]));
}

void join(int a, int b){
    int rootA = find(a), rootB = find(b);
    num[rootB] = rootA;
}

int main(){
    scanf("%d %d", &n, &d);
    init();
    for(int i=1; i<=n; i++)
        scanf("%d %d", &com[i].x, &com[i].y);
    char op;
    int p, q;
    while(~scanf("%c", &op)){
        if(op == 'O'){
            scanf("%d", &p);
            repaired[p] = true;
            for(int i=1; i<=n; i++){
                double dis = sqrt(sq(com[i].x - com[p].x) + sq(com[i].y - com[p].y));
                if(dis <= d && repaired[i])
                    join(p, i);
            }
        }else if(op == 'S'){
            scanf("%d %d", &p, &q);
            if(find(p) == find(q))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }//while
    return 0;
}
