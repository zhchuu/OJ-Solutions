// LongestSubstringWithoutRepeatingCharacters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<vector>
#define max(x,y) (x >= y)? x:y;
using namespace std;

int lengthOfLongestSubstring(string s)
{
	vector<int> hashmap(256, -1);
	int ans = 0, start = -1;
	for (int i = 0; i < s.length(); i++) {
		if (hashmap[s[i]] > start) //It means that s[i] appears 2 times from start to i. 
			start = hashmap[s[i]];
		hashmap[s[i]] = i;
		ans = max(ans, i - start);
	}
	return ans;
}


int main()
{

    return 0;
}

