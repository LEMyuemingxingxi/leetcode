class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        if(nums[0]>target) return 0;
        if(nums[right]<target) return nums.size();
        while(left<right){
            if(nums[left] == target) return left;
            if(nums[right] == target) return right;
            int mid = (left+right)/2;
            if(nums[mid]<target){
                left = mid+1;
            }else if (nums[mid] > target)
            {
                right = mid;
            }else{
                return mid;
            }
        }
        return left;
    }
};