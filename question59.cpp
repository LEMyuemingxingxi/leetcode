void backtrack(int n,int pre,int suf,vector<string> &res,string& path){
    if(suf==n){
        res.push_back(path);
        return;
    }
    if (pre < n) {
        path.push_back('(');
        backtrack(n, pre + 1, suf, res, path);
        path.pop_back();
    }

    if (suf < pre) {
        path.push_back(')');
        backtrack(n, pre, suf + 1, res, path);
        path.pop_back();
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        backtrack(n,0,0,res,path);
        return res;
    }
};