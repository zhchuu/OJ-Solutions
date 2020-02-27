/*
 * hdu1026 Ignatius and the Princess I
 * Hint: BFS, priority_queue
 * */

#include<iostream>
#include<cstring>
#include<queue>
#include<stdio.h>
using namespace std;
const int maxMN = 100+5;
char maze[maxMN][maxMN];
int visi[maxMN][maxMN];
struct condition{
	friend bool operator> (condition c1, condition c2){
		return (c1.mov.length() < c2.mov.length());
	}
	friend bool operator< (condition c1, condition c2){
		return (c1.mov.length() > c2.mov.length());
	}
	int x;//current x
	int y;//current y
	string mov;//u--up,d--down,l--left,r--right,f--fight
};
void findout(condition end){
	//cout<<"Get it!"<<" "<<end.mov<<endl;
	cout<<"It takes "<<end.mov.length()<<" seconds to reach the target position, let me show you the way."<<endl;
	int sec = end.mov.length();
	int xx=0,yy=0;
	int next_xx,next_yy;
	for(int s = 1;s<=sec;s++){
		switch(end.mov[s-1]){
			case 'u':next_xx = xx-1; next_yy = yy;break;
			case 'd':next_xx = xx+1; next_yy = yy;break;
			case 'l':next_xx = xx; next_yy = yy-1;break;
			case 'r':next_xx = xx; next_yy = yy+1;break;
			case 'f':next_xx = xx; next_yy = yy;break;
			default :break;
		}//switch
		cout<<s<<"s:";
		if(end.mov[s-1] == 'f')
			cout<<"FIGHT AT ("<<next_xx<<","<<next_yy<<")"<<endl;
		else
			cout<<"("<< xx <<","<< yy <<")->("<<next_xx<<","<<next_yy<<")"<<endl;
		xx = next_xx;
		yy = next_yy;
	}

}
int main(){
	int N,M;
	priority_queue<condition> q;
	bool isFind;
	while(cin>>N&&cin>>M){
		//initialize
		memset(maze,-1,sizeof(maze));
		memset(visi,0,sizeof(visi));
		isFind = false;
		while(!q.empty())
			q.pop();
		//input maze
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				cin>>maze[i][j];
		condition start;
		start.x = 0;
		start.y = 0;
		start.mov = "";
		q.push(start);
		//start BFS
		while(!q.empty()){//Every time you pop a condition from priority queue,
						  //you get the shortest path.
						  //Remember to judge if the position has walked already!!!!!!
						  //Because you get the shortest path, if the position has walked already,
						  //that means there was another much shorter path has been considered.
			condition temp = q.top();
			q.pop();
			//cout<<temp.mov<<endl;
			if(visi[temp.x][temp.y]==1)//remember!!!!!!!!!!!!!!!!!!
				continue;
			visi[temp.x][temp.y] = 1;
			char now = maze[temp.x][temp.y];
			if(now != 'X' && now != '.'){
				int times = now - '0';
				while(times--)
					temp.mov = temp.mov + "f";
			}//fight
			if(temp.x == N-1 && temp.y == M-1){
				//到达终点
				findout(temp);
				isFind = true;
				break;
			}//
			else{
				if(temp.x-1 >= 0 && maze[temp.x-1][temp.y]!='X' && visi[temp.x-1][temp.y]!=1){
					condition step;
					step.x = temp.x-1;
					step.y = temp.y;
					step.mov = temp.mov + "u";
					//visi[temp.x-1][temp.y] = 1;
					q.push(step);
				}//up
				if(temp.x+1 < N && maze[temp.x+1][temp.y]!='X' && visi[temp.x+1][temp.y]!=1){
					condition step;
					step.x = temp.x+1;
					step.y = temp.y;
					step.mov = temp.mov + "d";
					//visi[temp.x+1][temp.y] = 1;
					q.push(step);
				}//down
				if(temp.y-1 >= 0 && maze[temp.x][temp.y-1]!='X' && visi[temp.x][temp.y-1]!=1){
					condition step;
					step.x = temp.x;
					step.y = temp.y-1;
					step.mov = temp.mov + "l";
					//visi[temp.x][temp.y-1] = 1;
					q.push(step);
				}//left
				if(temp.y+1 < M && maze[temp.x][temp.y+1]!='X' && visi[temp.x][temp.y+1]!=1){
					condition step;
					step.x = temp.x;
					step.y = temp.y+1;
					step.mov = temp.mov + "r";
					//visi[temp.x][temp.y+1] = 1;
					q.push(step);
				}//right
			}//else
		}//while
		if(!isFind)
			cout<<"God please help our poor hero."<<endl;
		cout<<"FINISH"<<endl;
	}//while
	return 0;
}
