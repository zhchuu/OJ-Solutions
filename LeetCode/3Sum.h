#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> vec;
		if (nums.size() < 3)
			return vec;
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
				int low = i + 1, high = nums.size() - 1, sum = 0 - nums[i];
				while (low < high) {
					if (nums[low] + nums[high] == sum) {
						vector<int> temp;
						temp.push_back(nums[i]); temp.push_back(nums[low]); temp.push_back(nums[high]);//Èý¸öpush_back
						vec.push_back(temp);
						while (low < high&&nums[low] == nums[low + 1])	low++;
						while (low < high&&nums[high] == nums[high - 1])	high--;//±ÜÃâÖØ¸´
						low++; high--;
					}//if
					else if (nums[low] + nums[high] > sum)	high--;
					else low++;
				}//while
			}//if
		}//for
		return vec;
	}
	void print(vector<vector<int>> v)
	{
		for (int i = 0; i < v.size(); i++){
			vector<int> t = v[i];
			for (int j = 0; j < 3; j++) {
				cout << t[j] << " ";
			}
			cout << endl;
		}
	}
};

