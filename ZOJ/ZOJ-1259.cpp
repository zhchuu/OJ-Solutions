/*Sample Input

5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0


Sample Output

Yes
No

Yes
*/
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int>s;
	int n , i, j, out[1000], flag1 = 0;;
	while (cin >> n&&n)
	{
		
		if (n == 0) break;
		if (flag1 == 1)
			{
				flag1 = 0;
			}
		while (1)
		{
			j = 0;
			for (i = 0; i<n; i++)
			{
				cin >> out[i];
				if (i == 0 && out[i] == 0)
				{
					flag1 = 1;
					cout << endl;
					break;
				}
			}
			if (flag1 == 1)	break;
			for (i = 0; i<n; i++)
			{
				s.push(i + 1);
				while (s.top() == out[j])
				{
					s.pop();
					j++;
					if (s.empty()) break;
				}
			}
			if (s.empty())
			{
				cout << "Yes" << endl;
			}
			if (!s.empty())
			{
				cout << "No" << endl;
			}
			while (!s.empty()) { s.pop(); }
		}
	}
	return 0;
}
