class Solution {
public:
    void solve(vector<int>&nums, vector<int>& ans, int idx, vector<vector<int>>& res){
        res.push_back(ans);
        for(int i= idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            ans.push_back(nums[i]);
            solve(nums,ans,i+1,res);
            ans.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int>ans;
        solve(nums,ans,0,res);
        return res;

    }
};