#include<iostream>
#include<stack>
using namespace std;
stack<char>op;
stack<char>num;
int main()
{	
	int i=0;
	char shuru[101],val1,val2;
	while (cin.getline(shuru, 101))
	{
		while (shuru[i] != '\0')
		{
			switch (shuru[i])
			{
			case 'V':val1 = op.top;
				if (val1 = '!') { num.push('F'); }
				else if (val1 = '&')
				{
					val2 = num.top();
					if (val2 = 'V') { num.push('V'); }
					if (val2 = 'F') { num.push('F'); }
				}
				else if (val1 = '|')
				{
					val2 = num.top();
					if (val2 = 'V') { num.push('V'); }
					if (val2 = 'F') { num.push('V'); }
				}
				else num.push(shuru[i]); break;
			case 'F':val1 = op.top;
				if (val1 = '!') { num.push('V'); }
				else if (val1 = '&')
				{
					val2 = num.top;
					if (val2 = 'V') { num.push('F'); }
					if (val2 = 'F') { num.push('F'); }
				}
				else if (val1 = '|')
				{
					val2 = num.top;
					if (val2 = 'V') { num.push('V'); }
					if (val2 = 'F') { num.push('F'); }
				}
				else num.push(shuru[i]); break;
			case ')':
			case '(':
			case '!':
			case '&':
			case '|':op.push(shuru[i]); break;
			}

		}
	}
}