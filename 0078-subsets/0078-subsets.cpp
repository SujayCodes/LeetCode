class Solution {
public:
    // Take and dont take approach
    void helper(vector<int>& nums, int idx, vector<int>& v, vector<vector<int>> &res){
        int n=nums.size();
        if(idx==n){
            res.push_back(v);
            return;
        }

        v.push_back(nums[idx]);
        helper(nums, idx+1, v,res);

        v.pop_back();
        helper(nums, idx+1, v,res);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> res;
        helper(nums,0,v,res);
        return res;
    }
};

// For every element, we have exactly 2 choices:
// Take it or Don't take it.
// Example: [1,2,3] → for 1, either [1] or [].
// Use recursion to make these choices one by one.
// idx tells us which element we are currently deciding about.

// If we take the element, first add it to v:

// v.push_back(nums[idx]);

// Then move to the next element using idx + 1.

// After finishing the "take" choice, remove that element using:

// v.pop_back();

// This gives us the original v again, so we can now try the "don't take" choice.

// When idx == n, we have made a take/don't-take decision for every element. So the current v is one complete subset, and we store it:

// res.push_back(v);