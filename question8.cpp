class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> substr;
        int max = 0;
        for(char letter : s){
            auto it = find(substr.begin(),substr.end(),letter);
            if (it==substr.end())
            {
                substr.push_back(letter);
                if(substr.size()>max) max = substr.size();
            }else
            {
                substr.erase(substr.begin(),it+1);
                substr.push_back(letter);
            }
        }
        return max;
    }
};