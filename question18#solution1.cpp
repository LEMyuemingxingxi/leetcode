class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> rowZero(m, false), colZero(n, false);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) {
                    rowZero[i] = true;
                    colZero[j] = true;
                }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rowZero[i] || colZero[j])
                    matrix[i][j] = 0;
    }
};