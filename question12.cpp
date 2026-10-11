bool contain(int* target, int* cur){
    for(int i = 0; i <128; i++){
        if(target[i] > cur[i]) return false;
    }
    return true;
}

class Solution {
public:
    string minWindow(string s, string t) {
        int target[128] = {0};
        for(char letter : t){
            target[letter]++;
        }
        int cur[128] = {0};
        int left = 0, right  =0;
        pair<int,int> min = {INT_MAX,-1};

        while (right < s.size())
        {
            cur[s[right]]++;
            if(contain(target,cur)){
                while(1){
                    --cur[s[left]];
                    if(!contain(target,cur)){
                        cur[s[left]]++;
                        int len = right - left+1;
                        if (len<min.first)
                        {
                            min = {len,left};
                        }
                        
                        break;
                    }
                    ++left;
                }
            }
            ++right;
        }
        if(min.first == INT_MAX) return "";
        return s.substr(min.second,min.first);
    }
};
