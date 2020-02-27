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
		bool isOdd = ((size1 + size2) % 2 ? true : false);//����Ϊtrue
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
				}//Ҫi++����ΪĿǰi��λ���������ˣ�i++����һ��λ�á���Ϊֱ��break������û��ִ��for�е�i++
				else
					break;
			}
		}//for
		if (i <= middle) {//�ж��Ƿ�����ֱ��middle
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

