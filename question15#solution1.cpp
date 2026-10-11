class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> dq;
        for(int n : nums){
            dq.push_back(n);
        }
        int num;
        for(int i = 0; i < k; i++){
            num = dq.back();
            dq.pop_back();
            dq.push_front(num);
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = dq[i];
        }
    }
};
