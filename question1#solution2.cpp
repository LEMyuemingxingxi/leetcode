class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> target_pair;
        for(int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            auto it = seen.find(need);
            if(it != seen.end()){
                return {it->second,i};
            }
            seen[nums[i]] = i;
        }
    }
};