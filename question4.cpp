#include<vector>
using namespace std ;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(auto it = nums.begin(); it != nums.end();){
            if(*it == 0){
                ++cnt;
                it = nums.erase(it);
            }else{
                ++it;
            }
        }
        for(int i  = 0; i < cnt; i++){
            nums.push_back(0);
        }
    }
};