#include<iostream> 
#include<cstdio> 
#include<string> 
#include<stack> 
using namespace std;
struct Matrix
{
	char name;
	int r;
	int c;
};
int main()
{
	stack<Matrix> s;
	int i, j, n, sum;
	Matrix sym[26], A, B, temp;
	string str;
	bool flag;
	cin >> n;
	for (i = 0; i<n; i++)
		cin >> sym[i].name >> sym[i].r >> sym[i].c;
	while (cin >> str)
	{
		i = 0;
		sum = 0;
		flag = true;
		while (str[i] != '\0')
		{
			if (str[i] != '(')
			{
				if (str[i] >= 'A'&&str[i] <= 'Z')
				{
					for (j = 0; j<n; j++)
					{
						if (sym[j].name == str[i])
						{
							s.push(sym[j]);
							break;
						}
					}
				}
				else
				{
					if (str[i] == ')')
					{
						B = s.top();
						s.pop();
						A = s.top();
						s.pop();
						if (A.c == B.r)
						{
							temp.name = 'n';
							temp.r = A.r;
							temp.c = B.c;
							s.push(temp);
							sum = sum + A.r *A.c *B.c;
						}
						else
						{
							cout << "error" << endl;
							flag = false;
							break;
						}
					}

				}
			}
			i++;
		}
		while (!s.empty())
			s.pop();
		if (flag)
			cout << sum << endl;
	}
	return 0;
}