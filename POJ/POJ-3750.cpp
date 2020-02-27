#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N, W, S,i,j,pos,stand,count;
	char unknow;
	string std_name[64];
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> std_name[i];
	}
	cin >> W >> unknow >> S;
	if (W > N) return 0;
	pos = W - 1;
	count = 0;
	for (; count < N;count++)
	{
		pos = (pos + S - 1) % (N - count);
		cout << std_name[pos]<<endl;
		for (j=pos;j<N-count;j++)
		{
			std_name[j] = std_name[j + 1];
		}
	}
}