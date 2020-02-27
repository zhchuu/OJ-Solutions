/*
 * PAT L1-008
 * Try setw(n)
 * */

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int k = b-a;
	int m = k/5;
	int from = a;
	while(m--){
		int cnt = 5;
		while(cnt--)
			cout<<setw(5)<<setiosflags(ios::right)<<from++;
		cout<<endl;
	}
	while(from<=b)
		cout<<setw(5)<<setiosflags(ios::right)<<from++;
	cout<<endl;
	int sum = 0;
	for(int i=a;i<=b;i++)
		sum += i;
	cout<<"Sum = "<<sum<<endl;
}
