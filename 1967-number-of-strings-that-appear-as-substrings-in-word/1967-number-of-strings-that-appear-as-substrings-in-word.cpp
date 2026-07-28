class Solution {
public:
    int numOfStrings(vector<string>& nums, string word) {
        int count= 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(word.find(nums[i])==-1){
                continue;
            }
            else count++;
        }
        return count;
        
    }
};



// See how .find is used
/*

text = "Hello, welcome to the world."
index = text.find("welcome")
print(index)  # Output: 7 (The 'w' starts at index 7)  

text.find() always return index

*/