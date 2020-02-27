#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
const int maxN = 100 + 5;
int main()
{
	int kases;
	int height;
	int tree[maxN][maxN];
	int table[maxN][maxN];
	queue<pair<int,int>> q;
	cin>>kases;
	while(kases--){
		//init
		memset(tree,-1,sizeof(tree));
		memset(table,-1,sizeof(table));
		//input data
		cin>>height;
		for(int i=1;i<=height;i++){
			for(int j=1;j<=i;j++)
				cin>>tree[i][j];
		}//for
		//calculate
		table[1][1] = tree[1][1];
		pair<int,int> pa(1,1);
		q.push(pa);
		pair<int,int> temp;
		int x,y,down,rightDown;
		while(!q.empty()){
			temp = q.front();
			q.pop();
			x = temp.first;
			y = temp.second;
			if(x>=height || y>=height)
				continue;
			down = table[x][y] + tree[x+1][y];
			rightDown = table[x][y] + tree[x+1][y+1];
			//update table
			if(down > table[x+1][y]){
				table[x+1][y] = down;
				pair<int,int> pa(x+1,y);
				q.push(pa);
			}
			if(rightDown > table[x+1][y+1]){
				table[x+1][y+1] = rightDown;
				pair<int,int> pa(x+1,y+1);
				q.push(pa);
			}
			//cout<<"not empty!"<<endl;
		}//while
		int max = 0;
		for(int k = 1;k<=height;k++){
			if(table[height][k]>max)
				max = table[height][k];
		}
		cout<<max<<endl;
	}//while
	return 0;
}
