class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        int index = 0;
        int front = index+1;
        while(index < intervals.size()){
            if(front<intervals.size() && intervals[index][1]<=intervals[front][1]&&intervals[index][1]>=intervals[front][0]){
                intervals[index][1] = intervals[front][1];
                ++front;
            }else if (front<intervals.size() && intervals[index][1]>intervals[front][1])
            {
                ++front;
            }
            
            else{
                result.push_back(intervals[index]);
                index = front;
                front = index+1;
            }
        }
        return result;
    }
};
