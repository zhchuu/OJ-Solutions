class Solution {
 public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		if(strs.empty())
			return ans;

		map<string, vector<string>> m;
		for(int i=0; i<strs.size(); i++){
			string s = strs[i];
			sort(s.begin(), s.end());
			if(m.count(s) >= 1)
				m[s].push_back(strs[i]);
			else{
				m[s] = vector<string>();
				m[s].push_back(strs[i]);
			}
		}//for

		for(map<string, vector<string>>::iterator it=m.begin(); it!=m.end(); it++){
			ans.push_back(it->second);
		}//for

		return ans;
	}
};
