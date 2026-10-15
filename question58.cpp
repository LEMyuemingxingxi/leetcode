int sum(vector<int> &path){
    int sum =0;
    for(int num: path){
        sum+=num;
    }
    return sum;
}
void backtrack(vector<int>& candidates, int target, vector<vector<int>>& res,vector<int>& path, int start){
    if(sum(path)==target){
        res.push_back(path);
        return;
    }
    // for(int i = start; i <  candidates.size(); i++){
    if(start >= candidates.size()) return;
        path.push_back(candidates[start]);
        if(sum(path)>target){
            path.pop_back();
        }else{
            backtrack(candidates,target,res,path,start);
            path.pop_back();
            backtrack(candidates,target,res,path,start+1);
        }

    // }
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates,target,res,path,0);
        return res;
    }
};