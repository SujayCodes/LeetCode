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



// Subsets II — Logic/Theory

// The main difference between Subset I and Subset II is that in Subset II, the array can contain duplicates, but the answer must not contain duplicate subsets.



// 1. Sort the array first.

// Because after sorting, duplicate elements become adjacent. This allows us to easily detect duplicates.

// 2. Start with an empty subset.

// []

// Every subset we create is immediately added to the answer.

// 3. At every position, try choosing an element.



// []
//  ↓
// choose 1
//  ↓
// [1]

// Then continue recursively with the elements after 1.

// Similarly, we can choose 2, then another 2, etc.




// 4. Skip duplicate elements at the SAME recursion level.

// This is the most important concept.

// Suppose we are at:

// [1, 2, 2]
//     ↑  ↑

// If we choose the first 2 as the starting choice, choosing the second 2 as another starting choice would create the same subsets.

// Therefore:

// if(i > index && nums[i] == nums[i-1])
//     continue;

// means:

// "If this is not the first choice at this recursion level and it is equal to the previous element, skip it."

// But why can we still make [2,2]?

// This is the important part.

// We skip duplicate 2s at the same level, but once we choose the first 2, we go deeper into recursion.

// There, we are allowed to choose the second 2.

// So:

// Choose first 2
//      ↓
//    [2]
//      ↓
// Choose second 2
//      ↓
//   [2,2]  ✅

// But we don't create another identical branch:

// [] → second 2 ❌

// because the first 2 already created that branch.





// 5. Backtracking

// After choosing an element, we recursively explore all possibilities.

// Then:

// ans.pop_back();

// removes that element so we can try another choice.








// So the overall idea is:

// Sort
//   ↓
// Start with empty subset
//   ↓
// Add current subset to answer
//   ↓
// Try each possible element
//   ↓
// Skip duplicate at same level
//   ↓
// Choose element
//   ↓
// Recursively continue
//   ↓
// Remove element (backtrack)