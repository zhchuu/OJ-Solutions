#include<iostream>
using namespace std;
int main()
{
	void judge(int x);
	int n;
	cin >> n;
	if (n == 0) return 0;
	judge(n);
	for (;;)
	{
		cin >> n;
		if (n == 0) return 0;
		judge(n);
	}

	return 0;
}
void judge(int x)
{
	int num[17][17], i, j, count[17], down, up, record[17] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, y = x;
	for (i = 2; i < 17; i++)
	{
		count[i] = 0;
		y = x;
		for (j = 1; y > 0; j++)
		{

			num[i][j] = y % i;
			y = y / i;
			count[i]++;
		}
	}
	for (i = 2; i < 17; i++)
	{
		for (down = 1, up = count[i];; down++, up--)
		{
			if (num[i][down] != num[i][up])
				break;
			if ((num[i][down] == num[i][up]))
				if ((down >= up))
				{
					record[i] = i;
					break;
				}
		}
	}
	int flag;
	for (flag = 0, i = 1; i < 17; i++)
	{
		if (record[i] != 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "Number " << x << " is not a palindrom";
	if (flag == 1)
		cout << "Number " << x << " is palindrom in basis";
	for (i = 1; i < 17; i++)
	{
		if (record[i] != 0)
			cout << " " << record[i];
	}
	cout << endl;
}
/*
Sample Output

Number 17 is palindrom in basis 2 4 16
Number 19 is not a palindrom
*/