class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> preproduct(size);
        vector<int> sufproduct(size);
        int product = 1;
        for(int i = 0 ; i < size - 1; i++){
            product*=nums[i];
            preproduct[i] = product;
        }
        product = 1;
        for(int i = size-1; i > 0; --i){
            product*=nums[i];
            sufproduct[i] = product;
        }
        vector<int> result;
        result.push_back(sufproduct[1]);
        for(int i = 1; i < size-1; i++){
            result.push_back(preproduct[i-1]*sufproduct[i+1]);
        }
        result.push_back(preproduct[size-2]);
        return result;
    }
};
