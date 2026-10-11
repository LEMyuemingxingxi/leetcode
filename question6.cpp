class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;                 // 后面都 >0，不可能凑 0
            if (i > 0 && nums[i] == nums[i-1]) continue;  // 去重
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) ++l;
                else if (sum > 0) --r;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1]) ++l;  // 去重
                    while (l < r && nums[r] == nums[r-1]) --r;  // 去重
                    ++l; --r;
                }
            }
        }
        return res;
    }
};