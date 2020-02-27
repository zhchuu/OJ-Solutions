#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int maxstr = 12;
int main()
{
	map<string, string> dic;//foi,eng
	char eng[maxstr], foi[maxstr];
	while (true) {
		char isblank;
		if ((isblank = getchar()) == '\n')//
			break;
		int i = 0;
		eng[0] = isblank;//
		while ((isblank=getchar())!=' ')
			eng[++i] = isblank;
		eng[++i] = '\0';//
		cin >> foi;
		getchar();//
		dic[foi] = eng;//
	}//while
	string str;
	while (cin >> str) {
		if (dic.count(str))
			cout << dic[str] << endl;
		else
			cout << "eh" << endl;
	}
	return 0;
}
