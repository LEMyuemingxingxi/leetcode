void backtrack(string &digits,vector<string> &res,string &path,int start,map<char,string>& mp){
    if(path.size()==digits.size()){
        res.push_back(path);
        return;
    }
    for(int i = 0; i < mp[digits[start]].size(); i++){
        path.push_back(mp[digits[start]][i]);
        backtrack(digits,res,path,start+1,mp);
        path.erase(path.end()-1);
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> res;
        string path;
        backtrack(digits,res,path,0,mp);
        return res;
    }
};