/*
*zoj1942
*/
#include<iostream>
#include<stdio.h>
#include<queue>
#include<stdio.h>
#include<cmath>
#include<stack>
#include<memory.h>
using namespace std;
#define M 200+1
#define max(a,b) (a)>(b) ? (a):(b)
#define min(a,b) (a)<(b) ? (a):(b)
const int maxLen = 32767;
double G[M][M];
int n;
static int indx;//the indx of the input array
struct xy
{
	double x, y;
}input[M];
struct Distance
{
	double distval;
	double longestJump;
	int start;
	int end;
	int isVisited[M];
};
double shortestJump[M];//from v0 to i,the shortest *necessary* jump of all path
bool operator < (const Distance &a, const Distance &b)
{
	if (a.distval > b.distval)
		return true;
	else
		return  false;
}
priority_queue <Distance> PQ;
void Dijkstal(int v0)//start,end
{
	int i, j, k;
	Distance temp;
	double min = 32767;
	int pos = 0;
	for (i = 1; i < n; i++)
	{
		if (G[v0][i] < min)
		{
			min = G[v0][i];
			pos = i;
		}
	}
	shortestJump[pos] = G[v0][pos];
	temp.distval = G[v0][pos];
	temp.longestJump = G[v0][pos];
	temp.start = v0;
	temp.end = pos;
	temp.isVisited[pos] = 1;
	PQ.push(temp);
	//
	while (!PQ.empty())
	{
		Distance dist = PQ.top();
		PQ.pop();
		for (j = 1; j < n; j++)
		{
			Distance temp2;
			if (G[dist.end][j] != 32767 && dist.end != j && (dist.isVisited[j] != 1))//the path exist
			{
				if (dist.longestJump < G[dist.end][j])//update the longest jump of this path
					temp2.longestJump = G[dist.end][j];
				else
					temp2.longestJump = dist.longestJump;
				temp2.distval = dist.distval + G[dist.end][j];
				temp2.start = v0;
				temp2.end = j;
				for (int p = 0; p < n; p++)
					temp2.isVisited[p] = dist.isVisited[p];
				temp2.isVisited[j] = 1;
				if (j != 1)
					PQ.push(temp2);
				/*
				update the shortJump of this path
				*/
				if (temp2.longestJump < shortestJump[j])
					shortestJump[j] = temp2.longestJump;
			}
		}//end for
	}//end while
}
void Flody()
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == k || G[i][k] == maxLen)
				continue;
			for (int j = 0; j < n; j++)
			{
				if (j == k || G[k][j] == maxLen)
					continue;
				G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
			}
		}
	}
}
void calculate(double x, double y, int num)//x,y,order
{
	xy temp;
	temp.x = x;
	temp.y = y;
	double len, t;
	for (int i = 0; i < indx; i++)
	{
		t = (input[i].x - x)*(input[i].x - x) + (input[i].y - y)*(input[i].y - y);
		len = sqrt(t);
		G[i][num] = len;
		G[num][i] = len;
	}
	indx++;
}
void init()
{
	while (!PQ.empty())
		PQ.pop();
	indx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				G[i][j] = 0;
			else
				G[i][j] = 32767;
		}//end for
	}//end for
	for (int i = 0; i < n; i++)
		shortestJump[i] = 32767;
	shortestJump[0] = 0;
}
void displayBoard()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%lf ", G[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int kase = 1;
	while (scanf("%d", &n) && n)
	{
		init();
		double x, y;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &x, &y);
			input[i].x = x;
			input[i].y = y;
			calculate(x, y, i);
		}
		//displayBoard();
		int v0 = 0, v1 = 1;
		Flody();
		//displayBoard();
		//Dijkstal(v0);
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", kase++, G[0][1]/*shortestJump[v1]*/);
	}
	//printf("\n");
	return 0;
}
