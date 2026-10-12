class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();
        int upbound = 0, downbound = m-1;
        int leftbound = 0, rightbound = n-1;
        int row = 0,column = 0;
        while(1){
            if(upbound > downbound || leftbound > rightbound) break;
            row = upbound;
            column = leftbound;
            // right
            while (1)
            {
                result.push_back(matrix[row][column]);
                if(column >= rightbound) break;
                ++column;
            }
            ++upbound;
            ++row;
            if(upbound > downbound || leftbound > rightbound) break;
            // down
            while (1)
            {
                result.push_back(matrix[row][column]);
                if(row >= downbound) break;
                ++row;
            }
            --rightbound;
            --column;
            if(upbound > downbound || leftbound > rightbound) break;
            // left
            while (1)
            {
                result.push_back(matrix[row][column]);
                if(column <= leftbound) break;
                --column;
            }
            --downbound;
            --row;
            if(upbound > downbound || leftbound > rightbound) break;
            // up
            while (1)
            {
                result.push_back(matrix[row][column]);
                if(row <= upbound) break;
                --row;
            }
            ++leftbound;
            ++column;

            // cout << upbound << " " << downbound <<" " << leftbound << " " << rightbound << endl;

            
        }
        return result;
    }
};