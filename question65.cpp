class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left  = 0,right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        int lower = left;
        left  = 0,right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target+1)
                left = mid + 1;
            else
                right = mid;
        }
        int higher = left-1;
        if(lower<nums.size() && nums[lower]==target){
            return {lower,higher};
        }else{
            return {-1,-1};
        }
    }
};