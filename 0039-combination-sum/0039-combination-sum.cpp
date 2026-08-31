// Combination sum solving with recursion

class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<int>& v, vector<vector<int>> &res, int idx){
        if(target==0){
            res.push_back(v);
            return;
        }
        if(target < 0) return;
        for(int i=idx;i<candidates.size();i++){
            v.push_back(candidates[i]);
            helper(candidates,target-candidates[i],v,res,i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>v;
        helper(candidates, target, v,res,0);
        return res;
    }
};