class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int a = nums[n-2]; int b= nums[n-1];
        int ans =(a-1) * (b-1);
        return ans;

    }
};