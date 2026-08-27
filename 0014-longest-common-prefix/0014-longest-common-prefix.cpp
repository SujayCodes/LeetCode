class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1) return strs[0];

        sort(strs.begin(),strs.end());

        string s= "";
        
        string f = strs[0];
        string last = strs[n-1];
        int minlength = min(f.size(),last.size());

        
        for(int i=0;i<minlength;i++){
            if(f[i]==last[i]) s+=f[i];
            else break;
        }
        return s;

    }
};