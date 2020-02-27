/*
 * HDU-1043
 * Status: TLE
 */
#include<stdio.h>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<cstring>
#include<iostream>
#include<set>
#include<queue>
using namespace std;

struct node{
	string stat;
	string path;
}strt, tmp, nxt;

const int maxn = 3+1;
char map[maxn][maxn];
string org;
string aim = "12345678x";
set<string> vis;
queue<node> q;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char mov[4] = {'d', 'u', 'r', 'l'};
int x, y;

int getPos(string s){
	for(int i=0; i<s.size(); i++)
		if(s[i] == 'x')
			return i;
	return -1;
}

string bfs(){
	strt.stat = org;
	strt.path = "";
	q.push(strt);
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		if(tmp.stat == aim)
			return tmp.path;
		int pos = getPos(tmp.stat);
		int t_x = pos/3;
		int t_y = pos%3;
		// 4 directions
		for(int i=0; i<4; i++){
			int n_x = t_x + dir[i][0];
			int n_y = t_y + dir[i][1];
			if(n_x < 0 || n_x >=3 || n_y < 0 || n_y >= 3)
				continue;
			int n_pos = n_x*3 + n_y;
			// swap (t_x, t_y) and (n_x, n_y)
			string n_str = tmp.stat;
			char tp = n_str[pos];
			n_str[pos] = n_str[n_pos];
			n_str[n_pos] = tp;
			// insert
			if(vis.count(n_str) >= 1)
				continue;
			vis.insert(n_str);
			//cout<<"insert: "<<n_str<<" | swap "<<pos<<" "<<n_pos<<endl;
			nxt.stat = n_str;
			nxt.path = tmp.path + mov[i];
			q.push(nxt);
		}
	}
	return "unsolvable";
}

int main(){
	//input
	char input;
	while(cin>>input){
		map[0][0] = input;
		org = "";
		org += input;
		for(int i=0; i<3; i++)
		for(int j=0; j<3; j++){
			if(i==0 && j==0)
				continue;
			cin>>map[i][j];
			org += map[i][j];
			if(map[i][j] == 'x'){
				x = i;
				y = j;
			}
		}
	
		//init
		vis.clear();
		while(!q.empty())
			q.pop();

		//solve
		string ans = bfs();
		cout<<ans<<endl;
	}//while

	return 0;
}
