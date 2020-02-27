#include<iostream>
#include<cstring>
using namespace std;
const int M = 40 + 5;
int f[M];
int F(int idx){
	if(f[idx]!=-1)
		return f[idx];
	return (f[idx]=F(idx-1) + F(idx-2));
}
int main()
{
	int kases;
	int num;
	memset(f,-1,sizeof(f));
	f[1]=1;
	f[2]=1;
	cin>>kases;
	while(kases--){
		cin>>num;
		int ans = F(num);
		cout<<ans<<endl;
	}
	return 0;
}
