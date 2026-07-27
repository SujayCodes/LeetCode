class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        // same as non- overlapping intervals question
        int n= points.size();
        int result = 0;
        sort(points.begin(),points.end(),cmp);
        int lastpoint = points[0][1];
        for(int i=1;i<n;i++){
            if(lastpoint >= points[i][0]){
                result++;
            } else{
                lastpoint = points[i][1];
            }
        }
        // return result;     // This will give the non-overlapping   , so to get overlapping = n- noL
        int val = n-result;
        return val;
    }
};