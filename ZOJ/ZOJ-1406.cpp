/*
 *zoj1406
 */
#include<iostream>
#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;
#define M 30
#define N 50

#define Maxsize 100
int parent[Maxsize];

int G[M][M];
int n;

struct EdgeNode
{
	int start;
	int end;
	int cost;
}edge, result[M];

bool operator < (const EdgeNode &a, const EdgeNode &b)
{
	if (a.cost > b.cost) return true; else return false;
}

priority_queue<EdgeNode> PQ;

struct linknode {
	int data;
	struct linknode *next;
}*adj[M];

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
	int i, j;
	for (i = 0; i<n; i++)
		for (j = i + 1; j<n; j++)
			if (G[i][j] != 32767)
			{
				edge.cost = G[i][j];
				edge.start = i;
				edge.end = j;
				PQ.push(edge);
			}
}

int SetFind(int i)
{
	int r;
	for (r = i; parent[r] >= 0; r = parent[r]);
	while (i != r)
	{
		int s = parent[i];
		parent[i] = r;
		i = s;
	}
	return r;
}

void  SetUnion(int i, int j)
{
	int temp = parent[i] + parent[j];
	if (parent[j] < parent[i])
	{
		parent[i] = j; parent[j] = temp;
	}
	else
	{
		parent[j] = i; parent[i] = temp;
	}
}

void Krus()
{
	int pos1, pos2;
	int choose;
	memset(parent, -1, sizeof(parent));
	choose = 0;
	while (choose < n - 1)
	{
		edge = PQ.top(); PQ.pop();

		pos1 = SetFind(edge.start);
		pos2 = SetFind(edge.end);

		if (pos1 != pos2)
		{
			SetUnion(pos1, pos2);

			result[choose].start = pos1;
			result[choose].end = pos2;
			result[choose].cost = edge.cost;

			choose++;
		}

	}
}

void output()
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		cout << i << ":  (" << result[i].start << " ---> " << result[i].end << " ) : " << result[i].cost << endl;
	}
}
void init()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = i; j < M; j++)
		{
			G[i][j] = (i == j ? 0 : 32767);
		}
	}
	while (!PQ.empty())
		PQ.pop();
}
int getAns()
{
	int i, answer = 0;
	for (i = 0; i < n - 1; i++)
	{
		answer += result[i].cost;
	}
	return answer;
}
int main()
{
	char a, b;
	int links, weight;
	while (cin >> n&&n)
	{
		init();
		int kase = n - 1;
		while (kase--)
		{
			//scanf("%s %d", &a, &links);
			cin >> a >> links;
			while (links--)
			{
				//scanf("%s %d", &b, &weight);
				cin >> b >> weight;
				G[a - 'A'][b - 'A'] = weight;
			}//end while
		}//end while
		//
		Change();
		Krus();
		//
		int ans = getAns();
		cout << ans << endl;
	}

	return 0;
}
