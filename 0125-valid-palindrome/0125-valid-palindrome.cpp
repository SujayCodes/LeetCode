class Solution {
public:
    bool isPalindrome(string s) {
        
        string res = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                res += tolower(s[i]);
            }
        }
        
        string reversed = res;
        

        reverse(reversed.begin(), reversed.end());
        

        return res == reversed;
    }
};