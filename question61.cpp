bool isPalindrome(string str){
    int front = 0;
    int back = str.size()-1;
    while(front<back){
        if(str[front]!=str[back]) return false;
        ++front;
        --back;
    }
    return true;
}

void backtrack(string &s,vector<vector<string>> &res,vector<string> &path,string str,int start,int cnt){
    if(cnt==s.size()){
        res.push_back(path);
        return;
    }
    if(start>=s.size()) return;
    str.push_back(s[start]);
    if(isPalindrome(str)){
        path.push_back(str);
        backtrack(s,res,path,"",start+1,cnt+str.size());
        path.pop_back();
    }

    backtrack(s,res,path,str,start+1,cnt);


}

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(s,res,path,"",0,0);
        return res;
    }
};