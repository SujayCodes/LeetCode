class Solution {
public:
    void parenthesis(vector<string> &ans, string s, int open, int close, int n){
        if(close==n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            parenthesis(ans, s+'(',open+1, close,n);
        }
        if(close<open){
            parenthesis(ans, s+')',open, close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        parenthesis(ans,"",0,0,n);
        return ans;
    }
};