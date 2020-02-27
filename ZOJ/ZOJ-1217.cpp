#include<cstdio>
#include<queue>
#include<string>
#include<iterator>
#include<map>
#include<iostream>
using namespace std;
string goal = "12345678x";
queue<string>q;
map<string, string> M;
map<string, string>::iterator it;
void insertChild(string s1, string s2, int pos, int next_pos)
{
	s2 = s1;
	char temp;
	temp = s2[pos]; s2[pos] = s2[next_pos]; s2[next_pos] = temp;
	it = M.find(s2);
	if (it == M.end()) {
		M[s2] = s1;
		q.push(s2);
	}
}
void init()
{
	string s1 = goal, s2;
	q.push(s1);
	M[s1] = s1;
	int pos, next_pos;
	while (!q.empty())
	{
		s1 = q.front(); q.pop();
		for (pos = 0; pos < 9; pos++) {
			if (s1[pos] == 'x')break;
		}
		if (pos % 3 != 2) { next_pos = pos + 1; insertChild(s1, s2, pos, next_pos); }
		if (pos % 3 != 0) { next_pos = pos - 1; insertChild(s1, s2, pos, next_pos);  }
		if (pos / 3 != 0) { next_pos = pos - 3; insertChild(s1, s2, pos, next_pos); }
		if (pos / 3 != 2) { next_pos = pos + 3; insertChild(s1, s2, pos, next_pos); }
	}
}
int main()
{
	int i;
	M.clear();
	init();
	string str, s_par;
	char c;
	int p1, p2;
	while (cin>>c) {
		str = ""; 
		str += c;
		for (i = 2; i <= 9; i++) {
			cin >> c;
			str += c;
		}
		it = M.find(str);
		if (it == M.end())
			cout << "unsolvable" << endl;
		else {
			while (str != goal) {
				it = M.find(str);
				s_par = it->second;
				for (p1 = 0; p1 < 9; p1++) { if (str[p1] == 'x')break; }
				for (p2 = 0; p2 < 9; p2++) { if (s_par[p2] == 'x')break; }
				p1 = p2 - p1;
				if (p1 == 3)
					cout << "d";
				else if (p1 == 1)
					cout << "r";
				else if (p1 == -1)
					cout << "l";
				else if (p1 == -3)
					cout << "u";
				str = s_par;
			}//while
			cout << endl;
		}//2else
	}//1while
	return 0;
}
