#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
bool isIncreasing(vector<int>& nums)
{
	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i] > nums[i + 1])
			return false;
	}
	return true;
}
bool checkPossibility(vector<int>& nums)
{
	int modified = 0, i;
	int temp;
	vector<int>::iterator it;
	for (i = 0; i < nums.size() - 1; i++) {
		if (nums[i] > nums[i + 1])
		{
			temp = nums[i];
			it = nums.begin() + i;
			nums.erase(it);
			if (isIncreasing(nums))
				return true;
			else {
				nums.insert(nums.begin() + i, temp);
				temp = nums[i + 1];
				it = nums.begin() + i + 1;
				nums.erase(it);
				if (isIncreasing(nums))
					return true;
				else
					return false;
			}
		}//if
	}//for
	return true;
}
int main()
{
	vector<int> test0 = { 4,2,3 };
	vector<int> test1 = { 4,3,2 };
	vector<int> test2 = { 5,1,9 };
	vector<int> test3 = { 4,5,1,6 };
	vector<int> test4 = { 1,2,3 };
	vector<int> t[5] = { test0,test1,test2,test3,test4 };
	for (int i = 0; i < 5; i++)
	{
		if (checkPossibility(t[i])) {
			printf("%d + true\n", i);
		}
		else {
			printf("%d + false\n", i);
		}
	}
}