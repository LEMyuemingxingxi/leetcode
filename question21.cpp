class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0,column = n-1;
        while(row<m&&column>-1){
            if(matrix[row][column]==target){
                return true;
            }else if (matrix[row][column]>target)
            {
                --column;
            }else{
                ++row;
            }
        }
        return false;
    }
};