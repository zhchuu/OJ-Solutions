#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int i, sum = 0;
	char str[260];
	for (;;)
	{
		cin.getline(str, 260);
		if (str[0] == '#') return 0;
		for (i = 0; str[i] != 0; i++)
		{
			if (str[i] != ' ')
				sum = sum + (i + 1)*(str[i] - 64);
		}
		printf("%d", sum); printf("\n");
		sum = 0;
	}
	return 0;
}
/*
ACM
MID CENTRAL
REGIONAL PROGRAMMING CONTEST
ACN
A C M
ABC
BBC
#
*/