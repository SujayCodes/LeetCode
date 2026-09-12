class Solution {
public:
    bool detectCapitalUse(string s) {
        int upper = 0;
        int lower=0;
        for(char ch : s){
            if(isupper(ch)) upper++;
            else lower++;
        }

        if(upper==s.size() || lower==s.size() || (isupper(s[0]) && lower ==s.length()-1)){
            return true;
        }
        else return false;
    }
};