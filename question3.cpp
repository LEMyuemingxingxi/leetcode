#include<vector>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;

        for(int num: nums){
            hash.insert(num);
        }
        int sequence = 0;
        for(int num: hash){
            if(hash.find(num-1)!=hash.end()) continue;
            int len = 1;
            int cur = num;
            while(1){
                if(hash.find(cur+1)==hash.end()) break;
                ++cur;
                ++len;
            }
            if(len > sequence) sequence = len;
        }
        return sequence;
    }
};