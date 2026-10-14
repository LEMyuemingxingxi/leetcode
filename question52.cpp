class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxcnt = -1;
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty())
        {
            ++maxcnt;
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int,int> badorange = q.front();
                q.pop();
                int x = badorange.first, y = badorange.second;
                if(x-1>=0&&grid[x-1][y]==1) q.push({x-1,y}),grid[x-1][y]=2;
                if(y-1>=0&&grid[x][y-1]==1) q.push({x,y-1}),grid[x][y-1]=2;
                if(x+1<m&&grid[x+1][y]==1) q.push({x+1,y}),grid[x+1][y]=2;
                if(y+1<n&&grid[x][y+1]==1) q.push({x,y+1}),grid[x][y+1]=2;

            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        int iszero =1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]!=0){
                    iszero = 0;
                }
            }
        }
        if(iszero) return 0;
        return maxcnt;
    }
};