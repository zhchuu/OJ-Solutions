#include<iostream>
using namespace std;
int main()
{
	int n, d[10], d_bin[10][20], i, j;
	cin >> n;
	for (i = 0; i<n; i++)
	{
		cin >> d[i];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; d[i] != 0; j++)
		{
			d_bin[i][j] = d[i] % 2;
			d[i] = d[i] / 2;
			if (d_bin[i][j] == 1)
			{
				if (d[i] != 0)
					cout << j << " ";
				else
					cout << j << endl;
			}
		}
	}
	return 0;
}