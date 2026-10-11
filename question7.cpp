class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int sum = 0;
        while (left < right) {
            leftMax  = max(leftMax,  height[left]);
            rightMax = max(rightMax, height[right]);
            if (leftMax < rightMax) {
                // 左边是短板，left 位置的水由 leftMax 决定
                sum += leftMax - height[left];
                ++left;
            } else {
                sum += rightMax - height[right];
                --right;
            }
        }
        return sum;
    }
};