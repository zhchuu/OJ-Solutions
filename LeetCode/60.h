/* 
 * Leetcode 60. 
 */

class Solution {
 private:
	string ans = "";
 public:
	string getPermutation(int n, int k) {
		int t = k-1;
		int fac[n+1];
		fac[0] = 1;
		for(int i=1; i<=n; i++)
			fac[i] = fac[i-1] * i;

		string num_list = "";
		for(int i=1; i<=n; i++)
			num_list += char(i+48);
		for(int i=n; i>=1; i--){
			int d = ceil(t / fac[i-1]);
			t = t % fac[i-1];
			ans += num_list.at(d);
			num_list.erase(d, 1);
		}
		return ans;
	}
};
