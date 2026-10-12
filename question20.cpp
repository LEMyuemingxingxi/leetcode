class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for(int j = 0; j <=(m-1)/2; j++){
            for(int i = 0; i < m/2; i++){
                int temp1 = matrix[m-j-1][i];
                matrix[m-j-1][i] = matrix[i][j]; 
                int temp2 = matrix[m-i-1][m-j-1];
                matrix[m-i-1][m-j-1] = temp1;
                int temp3 = matrix[j][m-i-1];
                matrix[j][m-i-1] = temp2;
                matrix[i][j] = temp3;
                temp1 = matrix[m-j-1][i];
                matrix[m-j-1][i] = matrix[i][j]; 
                temp2 = matrix[m-i-1][m-j-1];
                matrix[m-i-1][m-j-1] = temp1;
                temp3 = matrix[j][m-i-1];
                matrix[j][m-i-1] = temp2;
                matrix[i][j] = temp3;
                temp1 = matrix[m-j-1][i];
                matrix[m-j-1][i] = matrix[i][j]; 
                temp2 = matrix[m-i-1][m-j-1];
                matrix[m-i-1][m-j-1] = temp1;
                temp3 = matrix[j][m-i-1];
                matrix[j][m-i-1] = temp2;
                matrix[i][j] = temp3;
            }
        }
        
    }
};