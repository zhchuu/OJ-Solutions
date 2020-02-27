/*
zoj1203
kruskal
*/
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<queue>
using namespace std;
struct xy
{
	double x, y;
};
#define M  100+5
#define N  10000+4

double G[M][M];
int n;
struct edgenode
{
	int node1;
	int node2;
	double weight;
}edge[N], result[M];

int adj[M];

int edgesum = 0;

void Input()
{
	int i, j;
	cin >> n;
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			cin >> G[i][j];
}
void Change()
{
	edgesum = 0;
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (G[i][j] != 32767)
			{
				k = edgesum - 1;
				while (k >= 0)
				{
					if (edge[k].weight>G[i][j])
					{
						edge[k + 1] = edge[k];
					}
					else break;
					k--;
				}
				edge[k + 1].weight = G[i][j];
				edge[k + 1].node1 = i;
				edge[k + 1].node2 = j;
				edgesum++;
			}
}
void Krus()
{
	int curnode1, curnode2;
	int k;
	int pos1, pos2;
	int curedge, choose;

	for (k = 0; k<n; k++)
		adj[k] = k;
	curedge = 0;
	choose = 0;
	while (choose<n - 1)
	{
		curnode1 = edge[curedge].node1; curnode2 = edge[curedge].node2;
		pos1 = curnode1;  pos2 = curnode2;
		while (adj[pos1] != pos1) pos1 = adj[pos1];
		while (adj[pos2] != pos2) pos2 = adj[pos2];
		if (pos1 == pos2) { curedge++; continue; }
		adj[pos2] = pos1;
		result[choose].node1 = pos1;
		result[choose].node2 = pos2;
		result[choose].weight = edge[curedge].weight;
		choose++;
		curedge++;
	}
}
void output()
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		printf("%d:(%d--->%d):%lf\n", i, result[i].node1, result[i].node2, result[i].weight);
	}
}
double getans()
{
	int i;
	double aa = 0;
	for (i = 0; i < n - 1; i++)
		aa += result[i].weight;
	return aa;
}
int main()
{
	int kase = 0;
	while (scanf("%d", &n) && n)
	{
		xy inputs[105];
		for (int k = 0; k < n; k++)
		{
			scanf("%lf%lf", &inputs[k].x, &inputs[k].y);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (i == j)//
					G[i][j] = 0;
				else
				{
					double temp = (inputs[i].x - inputs[j].x)*(inputs[i].x - inputs[j].x) + (inputs[i].y - inputs[j].y)*(inputs[i].y - inputs[j].y);
					double result = sqrt(temp);
					G[i][j] = result;
				}
			}//end for
		}//end for

		 //Input
		Change();
		Krus();

		double ans = getans();
		if (kase > 0)
			printf("\n");
		printf("Case #%d:\n", ++kase);
		printf("The minimal distance is: %.2lf\n", ans);//tag
	}
	return 0;
}
