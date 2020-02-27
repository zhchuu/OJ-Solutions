#include<stdio.h>
const int maxn = 35000;
int parent[maxn];
int find(int x)
{
	int root = x;
	while (parent[root] >= 0) {
		root = parent[root];
	}
	int temp;
	while (x != root)//
	{
		temp = parent[x];
		parent[x] = root;
		x = temp;
	}
	return root;
}
bool unite(int a, int b)
{
	a = find(a);
	b = find(b);
	/*if (a < b)
		parent[b] = a;
	else if (a > b)
		parent[a] = b;*/
	if (a == b)return false;
	parent[a] += parent[b];
	parent[b] = a;
	return true;
}
void init()
{
	for (int i = 0; i < maxn; i++)
		parent[i] = -1/*i*/;
}
int main()
{
	int i, j;
	int numOfpeo, numOfgop, numOfeachgop, peo, firstpeo;
	while (scanf("%d%d", &numOfpeo, &numOfgop) && numOfpeo) 
	{
		init();
		for (i = 0; i < numOfgop; i++) 
		{
			scanf("%d%d", &numOfeachgop, &firstpeo);//input the size of a group
			for (j = 1; j < numOfeachgop; j++)
			{
				scanf("%d", &peo);
				unite(firstpeo, peo);
			}//for
		}//for
		/*int ans = 1;
		for (i = 1; i < numOfpeo; i++) {
			if ( find(i) == 0)
				ans++;
		}
		printf("%d\n", ans);*/
		printf("%d\n", -parent[find(0)]);
	}
}
