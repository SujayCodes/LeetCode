class Solution {
public:
    bool isPalindrome(string s) {
        string res= "";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                res += tolower(s[i]);
            }
        }

        string rev = res;
        reverse(rev.begin(),rev.end());
        return res==rev;
    }
};