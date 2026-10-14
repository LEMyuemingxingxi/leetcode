class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,int> mp;
        int m = prerequisites.size();
        for(int i = 0; i<m;i++){
            mp[prerequisites[i][0]]++;
        }
        for(int i = 0; i<m;i++){
            if(mp.find(prerequisites[i][1])==mp.end()) mp[prerequisites[i][1]] = 0;
        }
        while(mp.size()){
            int foundKey = -1;
            for (auto& [key, value] : mp) {
                if (value == 0) {
                    foundKey = key;
                    break;
                }
            }
            if(foundKey == -1) return false;
            mp.erase(foundKey);
            for(int i = 0; i<m;i++){
                if(prerequisites[i][1]==foundKey){
                    mp[prerequisites[i][0]]--;
                }
            }
        }
        return true;
    }
};