/*
 * ZOJ-3321
 */

#include<stdio.h>
#include<memory.h>
using namespace std;

const int maxn = 10 + 2;
int n, m;
int graph[maxn];
int degree[maxn];

void init(){
    memset(graph, -1, sizeof(graph));
    memset(degree, 0, sizeof(degree));
}

int find(int x){
    if(graph[x] == -1)
	return x;
    else
	return graph[x] = find(graph[x]);
}

void link(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    if(root_a != root_b)
	graph[root_b] = root_a;
}

bool validate(){
    for(int i=1; i<=n; i++){
	if(degree[i] != 2)
	    return false;
    }
    for(int i=2; i<=n; i++){
	if(find(i) != find(1))
	    return false;
    }
    return true;
}

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
	init();
	for(int i=0; i<m; i++){
	    int a, b;
	    scanf("%d %d", &a, &b);
	    degree[a] += 1;
	    degree[b] += 1;
	    link(a, b);
	}
	// validate
	if(validate())
	    printf("YES\n");
	else
	    printf("NO\n");
    }

    return 0;
}
