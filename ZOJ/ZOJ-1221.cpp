/*
 *zoj1221
 *flody
*/
#include<stdio.h>
using namespace std;
#define min(a,b) (a)<(b) ? (a):(b)
const int numOfVertics = 20 + 1;
int dis[numOfVertics][numOfVertics];
int shortestPath[numOfVertics][numOfVertics];
void init()
{
	for (int i = 1; i < numOfVertics; i++)
	{
		for (int j = 1; j < numOfVertics; j++)
		{
			dis[i][j] = 32767;
		}
	}
}
void initshortestPath()
{
	for (int i = 1; i < numOfVertics; i++)
	{
		for (int j = 1; j < numOfVertics; j++)
		{
			shortestPath[i][j] = dis[i][j];
		}
	}
}
void flody()
{
	for (int k = 1; k < numOfVertics; k++)
	{
		for (int i = 1; i < numOfVertics; i++)
		{
			for (int j = 1; j < numOfVertics; j++)
				shortestPath[i][j] = min(shortestPath[i][j], shortestPath[i][k] + shortestPath[k][j]);
		}//end for
	}//end for
}
int main()
{
	int index = 1, num, order;
	while (scanf("%d", &num) != EOF)
	{
		init();
		for (int k = 0; k < num; k++) {//the 1th contries
			scanf("%d", &order);
			dis[1][order] = 1;
			dis[order][1] = 1;
		}
		for (int j = 2; j <= 19; j++){//input the rest of order
			scanf("%d", &num);
			for (int k = 0; k < num; k++) {
				scanf("%d", &order);//the contries that connect with j
				dis[j][order] = 1;
				dis[order][j] = 1;
			}
		}
		initshortestPath();
		flody();
		int kase, first, second;
		scanf("%d", &kase);
		printf("Test Set #%d\n", index++);
		while (kase--) {
			scanf("%d %d", &first, &second);
			printf("%d to %d: %d\n", first, second, shortestPath[first][second]);
		}//end while
		printf("\n");
	}//end while
	return 0;
}
