#include<cstdio>
#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;
set<string> dict;
int main() 
{
	string input, buf;
	while (cin >> input) {
		for (int i = 0; i < input.length(); i++) {
			if (isalpha(input[i]))	input[i] = tolower(input[i]);
			else
				input[i] = ' ';
		}//for
		stringstream ss(input);
		while (ss >> buf)	dict.insert(buf);
	}//while
	for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
		cout << *it << "\n";
	return 0;
}