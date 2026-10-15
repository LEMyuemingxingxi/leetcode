void backtrack(pair<int,int> p,bool& found, int index,vector<vector<char>>& board, string& word,vector<vector<bool>>& used){
    if (index == word.size())
    {
        found = 1;
        return;
    }
    if (p.first+1<board.size()&&!used[p.first+1][p.second]&&board[p.first+1][p.second]==word[index])
    {
        used[p.first+1][p.second] = true;
        
        backtrack({p.first + 1, p.second},found,index+1,board,word,used);
        used[p.first+1][p.second] = false;
    }
    
    if (p.first-1>=0&&!used[p.first-1][p.second]&&board[p.first-1][p.second]==word[index])
    {
        used[p.first-1][p.second] = true;
        backtrack({p.first - 1, p.second},found,index+1,board,word,used);
        used[p.first-1][p.second] = false;
    }

    if (p.second+1<board[0].size()&&!used[p.first][p.second+1]&&board[p.first][p.second+1]==word[index])
    {
        used[p.first][p.second+1] = true;
        backtrack({p.first, p.second+1},found,index+1,board,word,used);
        used[p.first][p.second+1] = false;
    }

    if (p.second-1>=0&&!used[p.first][p.second-1]&&board[p.first][p.second-1]==word[index])
    {
        used[p.first][p.second-1] = true;
        backtrack({p.first, p.second-1},found,index+1,board,word,used);
        used[p.first][p.second-1] = false;
    }
    
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        

        vector<pair<int,int>> start;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for(int i = 0; i<m;i++){
            for(int j = 0; j < n; j++){
                if(word[0]==board[i][j]) start.push_back({i,j});
            }
        }
        for(auto p: start){
            used[p.first][p.second] = true;
            backtrack(p,found,1,board,word,used);
            used[p.first][p.second] = false;
            if(found) return true;
        }
        return false;
    }
};