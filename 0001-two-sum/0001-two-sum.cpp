class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> res;
        int n= arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j]==target){
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
    
};