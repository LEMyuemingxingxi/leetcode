class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int minpresum = 0;
        int ans = INT_MIN;
        for(int num : nums){
            sum+=num;
            ans = max(ans,sum - minpresum );
            if(sum < minpresum) minpresum = sum;
        }
        
        return ans;

    }
};