#include<iostream>
#include<queue>
using namespace std;
struct xoy
{
	int x;
	int y;
	int count;
};
int main()
{
	queue<xoy> q;//´æ·Åµã
	xoy start, end;
	char input_start[3], input_end[3];
	while ((cin >> input_start >> input_end) && input_start&&input_end) {
		start.x = input_start[1];
		start.y = input_start[0];
		start.count = 0;
		end.x = input_end[1];
		end.y = input_end[0];
		q.push(start);
		while(q.front().x!=end.x||q.front().y!=end.y){
			xoy jump[8] = {
			{ q.front().x + 1,q.front().y + 2,q.front().count + 1 },//
			{ q.front().x + 2,q.front().y + 1,q.front().count + 1 },//
			{ q.front().x + 2,q.front().y - 1,q.front().count + 1 },//
			{ q.front().x + 1,q.front().y - 2,q.front().count + 1 },//
			{ q.front().x - 1,q.front().y - 2,q.front().count + 1 },//
			{ q.front().x - 2,q.front().y - 1,q.front().count + 1 },//
			{ q.front().x - 2,q.front().y + 1,q.front().count + 1 },//
			{ q.front().x - 1,q.front().y + 2,q.front().count + 1 } 
			};//array
			q.pop();
			for (int i = 0; i < 8; i++) {
				if (jump[i].x > 48 && jump[i].x < 57 && jump[i].y>96 && jump[i].y < 105)
					q.push(jump[i]);
			}//for
		}//while
		cout << "To get from " << input_start[0] << input_start[1] << " to " << input_end[0] << input_end[1] << " takes " << q.front().count << " knight moves." << endl;
		while (!q.empty())
			q.pop();
	}//while
	return 0;
}
