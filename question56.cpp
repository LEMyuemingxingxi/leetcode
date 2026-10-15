
void backtrack(vector<int>& nums,vector<vector<int>>& res,vector<int>& path,int start){
    res.push_back(path);
    for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtrack(nums, res, path, i + 1);
        path.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums,res,path,0);
        return res;
    }
};