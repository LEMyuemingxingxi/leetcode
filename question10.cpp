class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int,int> mp{{0,1}};
        for(int x: nums){
            sum+=x;
            ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};