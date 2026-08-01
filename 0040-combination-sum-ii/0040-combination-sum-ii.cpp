class Solution {
public:
    vector<vector<int>> result;
    void f(vector<int>& cand, int t, int idx, vector<int> &subset){
        if(t==0){
            result.push_back(subset);
            return;
        }
        if(idx==cand.size()) return;
        if(cand[idx]<=t){
            subset.push_back(cand[idx]);
            f(cand,t-cand[idx],idx+1,subset);
            subset.pop_back();
        }
        // skip repeating characters
        int j=idx+1;
        while(j<cand.size() && cand[j]==cand[j-1]) j++;
        f(cand,t,j,subset);
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());

        vector<int>subset;
        result.clear();
        f(cand,target,0,subset);
        return result;
    }
};