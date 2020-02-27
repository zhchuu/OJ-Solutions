#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int size1 = nums1.size(), size2 = nums2.size();
		int middle = (size1 + size2) / 2;
		bool isOdd = ((size1 + size2) % 2 ? true : false);//奇数为true
		bool isAssigned = false;
		vector<double> sorted(middle + 1);
		int pos1 = 0, pos2 = 0, i;
		for (i = 0; i <= middle; i++)
		{
			if ((pos2 < size2) && (pos1 < size1) && nums1[pos1] <= nums2[pos2]) {
				sorted[i] = nums1[pos1];
				pos1++;
				isAssigned = true;
			}
			else if ((pos2 < size2) && (pos1 < size1) && nums1[pos1] > nums2[pos2]) {
				sorted[i] = nums2[pos2];
				pos2++;
				isAssigned = true;
			}
			if (pos1 >= size1 || pos2 >= size2){
				if (isAssigned){
					i++; break;
				}//要i++，因为目前i的位置有数字了，i++是下一个位置。因为直接break，所以没有执行for中的i++
				else
					break;
			}
		}//for
		if (i <= middle) {//判断是否排序直到middle
			if (pos1 >= size1) {
				while (i <= middle) {
					sorted[i] = nums2[pos2];
					pos2++; i++;
				}//while
			}//if
			else if (pos2 >= size2) {
				while (i <= middle) {
					sorted[i] = nums1[pos1];
					pos1++; i++;
				}//while
			}//else if
		}//if
		if (isOdd)
			return sorted[middle];
		else
			return (sorted[middle] + sorted[middle - 1]) / 2;
	}
};

