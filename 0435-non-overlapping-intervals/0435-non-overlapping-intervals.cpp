class Solution {
public:
    bool static cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int result = 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int lastendtime= intervals[0][1];
        for(int i=1;i<n;i++){
            if(lastendtime>intervals[i][0]){
                result++;
            }
            else{
                lastendtime= intervals[i][1];
            }
        }
        return result;
    }
};





