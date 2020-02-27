#include<cstdio>
static int max;
static int n = 4;
char board[4][4];
bool canset(int x, int y)
{
	for (int i = x - 1; i >= 0; i--) {//up
		if (board[i][y] == 'X')
			break;
		else if (board[i][y] == 'o')
			return false;
	}
	for (int j = y - 1; j >= 0; j--) {//left
		if (board[x][j] == 'X')
			break;
		else if (board[x][j] == 'o')
			return false;
	}
	return true;
}
void DFS(int pos,int count)//
{
	if (pos >= n*n) {//
		if (count > max)
			max = count;
		return;
	}
	else
	{
		int x = pos / n;
		int y = pos%n;
		if (board[x][y]=='.'&&canset(x, y)) {
			board[x][y] = 'o';
			DFS(pos + 1, count + 1);
			board[x][y] = '.';
		}
		DFS(pos + 1, count);
	}
}
void init()
{
	max = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = '.';
		}
	}
}
int main()
{
	while (scanf("%d", &n) && n) {
		init();
		for (int i = 0; i < n; i++) {
			scanf("%s", &board[i]);
		}
		int p = 0, cot = 0;
		DFS(p, cot);
		printf("%d\n", max);
	}
}

/*
Sample input:
4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
0
Sample output:
5
1
5
2
4
*/
