class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];   // 以 i 结尾的最大和
        int ans = nums[0];   // 全局最大和

        for (int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};