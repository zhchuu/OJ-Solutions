#include<stdio.h>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
class quadtree
{
public:
	char value[3];//00->0,01->1,1->1
	quadtree *child[4];
	quadtree()
	{
		child[0] = child[1] = child[2] = child[3] = 0;
	}
	bool operator == (const quadtree &p) const
	{
		if (strcmp(value, "1")==0 || strcmp(value, p.value) != 0)
			return 0;
		else
			return 1;
	}
};
quadtree *head;
char MAP[520][520], ans[10000], str[5];
int N;
void init()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &MAP[i][j]);
		}
	}
	str[4] = 0;
	memset(ans, 0, sizeof(ans));
}
quadtree *DFS(int r, int c, int len)
{
	int i;
	bool f = 1;
	quadtree *temp = new quadtree;
	if (len == 1) {
		temp->value[0] = '0';
		temp->value[1] = '0' + MAP[r][c];//make the value same as the MAP[r][c]. Because it only left MAP[r][c]
		temp->value[2] = 0;
		return temp;
	}
	len = len / 2;
	temp->child[0] = DFS(r, c, len);
	temp->child[1] = DFS(r, c + len, len);
	temp->child[2] = DFS(r + len, c, len);
	temp->child[3] = DFS(r + len, c + len, len);//all child DFS
	for (i = 1; i < 4; i++) {
		if (!(*temp->child[0] == *temp->child[i])) {//if four children are not the same
			f = 0;
			break;
		}
	}
	if (f) 
	{//if same,combine four children and set a right value
		strcpy(temp->value, temp->child[0]->value);
		for (i = 0; i < 4; i++) 
		{
			delete temp->child[i];//delete all children
			temp->child[i] = 0;
		}//for
	}//if
	
	else
		strcpy(temp->value, "1");
	return temp;
}
void funtion(char s1[])
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum = sum * 2 + s1[i];
	printf("%0X", sum);
}
void print()
{
	int pos, i, jj, j;
	quadtree *temp;
	queue<quadtree *> q;
	q.push(head);
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		strcat(ans, temp->value);
		if (!(temp->child[0] == 0)) {
			for (int i = 0; i < 4; i++) {
				q.push(temp->child[i]);
			}//for
		}//if
		delete temp;
	}
	int slen = strlen(ans);
	pos = 0;
	if (slen % 4 != 0)
	{
		i = slen % 4;
		for (j = 0; j<4 - i; j++) str[j] = 0;
		for (jj = j; jj<4; jj++) str[jj] = ans[pos++] - '0';
		funtion(str);
	}

	for (i = pos; i<slen; i += 4)
	{
		for (j = 0; j<4; j++)
			str[j] = ans[i + j] - '0';
		funtion(str);
	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int u = 0; u<t; u++)
	{
		init();
		head = DFS(0, 0, N);
		print();
	}
	return 0;
}
