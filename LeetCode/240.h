/*
    240. Search a 2D Matrix II
    Time: O(m+n)
    Space: O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int height = matrix.size(), width = matrix[0].size();
        int i = 0, j = width - 1;
        while(i<height && j>=0){
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] > target)
                j--;
            else
                i++;
        }//while

        return false;
    }
};
