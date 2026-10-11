class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divide(nums, 0, nums.size() - 1);
    }

private:
    int divide(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];

        int mid = l + (r - l) / 2;
        int leftMax  = divide(nums, l, mid);
        int rightMax = divide(nums, mid + 1, r);

        // 跨中点：从中点往左的最大后缀和
        int sum = 0, leftSum = INT_MIN;
        for (int i = mid; i >= l; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        // 从中点+1 往右的最大前缀和
        sum = 0;
        int rightSum = INT_MIN;
        for (int i = mid + 1; i <= r; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        int crossMax = leftSum + rightSum;
        return max({leftMax, rightMax, crossMax});
    }
};