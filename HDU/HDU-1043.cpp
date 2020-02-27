/*
 * HDU-1043
 * Hint: print table
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

const int N = 4e5;
int fac[] = {1,1,2,6,24,120,720,5040,40320};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char mov[4] = {'d', 'u', 'r', 'l'};// reverse!!!!!!!!! Because bfs starts from 123456780
vector<char> table[N];
bool vis[N];

struct node{
	int stat[9], loc, cantor;
	vector<char> path;
};

int Cantor(int *s,int n){
    int sum=0;
    for(int i=0;i<9;i++)
    {
        int num=0;
        for(int j=i+1;j<9;j++)
            if(s[j]<s[i])num++;
        sum+=(num*fac[9-i-1]);
    }
    return sum+1;
}

void bfs(){
	memset(vis, 0, sizeof(vis));
	queue<node> q;
	node cur, nxt;
	for(int i=0; i<8; i++)
		cur.stat[i] = i+1;
	cur.stat[8] = 0;
	cur.loc = 8;
	cur.cantor = 46234; // 123456780
	q.push(cur);
	while(!q.empty()){
		cur = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int tx = cur.loc/3 + dir[i][0];
			int ty = cur.loc%3 + dir[i][1];
			int tz = tx*3 + ty;
			if(tz >= 0 && tx < 3 && ty < 3 && tx >= 0 && ty >= 0){
				nxt = cur;
				nxt.loc = tz;
				nxt.stat[cur.loc] = nxt.stat[nxt.loc];
				nxt.stat[nxt.loc] = 0;
				nxt.cantor = Cantor(nxt.stat, 9);
				if(!vis[nxt.cantor]){
					vis[nxt.cantor] = true;
					nxt.path.push_back(mov[i]);
					q.push(nxt);
					table[nxt.cantor] = nxt.path;
				}//if
			}//if
		}//for
	}//while
}

int main(){
    bfs();
	char input;
	while(cin>>input){
		node tmp;
		if(input == 'x')
			tmp.stat[0] = 0;
		else
			tmp.stat[0] = input - '0';
		for(int i=1; i<=8; i++){
			cin>>input;
			if(input == 'x')
				tmp.stat[i] = 0;
			else
				tmp.stat[i] = input - '0';
		}//for
		tmp.cantor = Cantor(tmp.stat, 9);
		if(vis[tmp.cantor] == 0)
			cout<<"unsolvable";
		else{
			for(int i=table[tmp.cantor].size()-1; i>=0; i--)
				cout<<table[tmp.cantor][i];
		}
		cout<<endl;
	}//while
	return 0;
}
