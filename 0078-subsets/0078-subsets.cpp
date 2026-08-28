class Solution {
public:
    void helper(vector<int>& nums, int idx, vector<int> &v, vector<vector<int>> & res){
        int n= nums.size();
        if(idx==n){
            res.push_back(v);
            return;
        }

        // Add
        v.push_back(nums[idx]);
        helper(nums,idx+1,v,res);

        // Don't add
        v.pop_back();
        helper(nums,idx+1,v,res);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> res;
        helper(nums, 0, v,res);
        return res;
    }
};