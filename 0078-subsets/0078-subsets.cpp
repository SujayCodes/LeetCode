class Solution {
public:
    void helper(vector<int>& nums, int idx , vector<int>& v, vector<vector<int>>& res){
        int n= nums.size();
        if(idx==n){
            res.push_back(v);
            return;
        }

        // Take the current element
        v.push_back(nums[idx]);
        helper(nums,idx+1,v, res);
        // Don't take the first element
        v.pop_back();
        helper(nums,idx+1,v, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        helper(nums, 0, v, res);
        return res;
    
    }
};