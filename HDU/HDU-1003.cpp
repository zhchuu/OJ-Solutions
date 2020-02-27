#include<iostream>
#include<cstring>
using namespace std;
const int maxN = 100000 + 5;
int main(){
	int kase;
	int N;
	int dp[maxN];
	int num[maxN];
	cin>>kase;
	for(int k =1;k<=kase;k++){
		memset(dp,-1,sizeof(dp));
		memset(num,-1,sizeof(num));
		cin>>N;
		for(int i=1;i<=N;i++)
			cin>>num[i];
		dp[1] = num[1];
		int ans = dp[1],begin=1,end=1;
		int x = 1,y = 1;
		for(int i=2;i<=N;i++){
			if(dp[i-1] + num[i] >= num[i]){
				dp[i] = dp[i-1] + num[i];
				y = i;
			}
			else{
				dp[i] = num[i];
				x = y = i;
			}
			if(dp[i] > ans){
				ans = dp[i];
				begin = x;
				end = y;
			}
		}//for
		cout<<"Case "<<k<<":"<<endl;
		cout<<ans<<" "<<begin<<" "<<end<<endl;
		if(k!=kase)
			cout<<endl;
	}//for
	return 0;
}
