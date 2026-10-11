class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size);
        int product = 1;
        ans[0] =1;
        for(int i = 0 ; i < size - 1; i++){
            product*=nums[i];
            ans[i+1] = product;
        }
        int right =1;
        for(int i = size-1; i > 0; i--){
            right*=nums[i];
            ans[i-1]*=right;
        }
        return ans;
    }
};