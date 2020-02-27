/*
Sample Input
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6
Sample Output
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.
*/

#include<iostream>
#include<queue>
struct xoy
{
	int x;
	int y;
	int count;
};
using namespace std;
int main()
{
	char shuru[6];
	cin.getline(shuru, 6);
	while (shuru[0] != '\0')
	{
		int i;
		xoy start;
		xoy end;
		queue<xoy>q;
		start.x = shuru[1]; start.y = shuru[0]; start.count = 0;
		end.x = shuru[4]; end.y = shuru[3];
		q.push(start);
		while (q.front().x != end.x || q.front().y != end.y)
		{
			xoy jump[8] = { {q.front().x + 1,q.front().y + 2,q.front().count + 1},//
						 { q.front().x + 2,q.front().y + 1,q.front().count + 1 },//
						 { q.front().x + 2,q.front().y - 1,q.front().count + 1 },//
						 { q.front().x + 1,q.front().y - 2,q.front().count + 1 },//
						 { q.front().x - 1,q.front().y - 2,q.front().count + 1 },//
						 { q.front().x - 2,q.front().y - 1,q.front().count + 1 },//
						 { q.front().x - 2,q.front().y + 1,q.front().count + 1 },//
						 { q.front().x - 1,q.front().y + 2,q.front().count + 1 } };//
			q.pop();
			for (i = 0; i < 8; i++)
			{
				if (jump[i].x>48 && jump[i].x < 57 && jump[i].y>96 && jump[i].y < 105)
				{
					q.push(jump[i]);
				}
			}//for
		}//while
		cout << "To get from " << shuru[0] << shuru[1] << " to " << shuru[3] << shuru[4] << " takes " << q.front().count << " knight moves." << endl;
		while (!q.empty())
		{
			q.pop();
		}
		cin.getline(shuru, 6);
	}//while
	return 0;
}