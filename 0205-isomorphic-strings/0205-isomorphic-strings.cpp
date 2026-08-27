class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        map<char, char> mp1;
        map<char, char> mp2;

        for (int i = 0; i < s.size(); i++) {

            // s -> t mapping
            if (mp1.count(s[i])) {
                // Mapping already exists, check if it matches
                if (mp1[s[i]] != t[i]) {
                    return false;
                }
            }
            else {
                // New character, create its mapping
                mp1[s[i]] = t[i];
            }

            // t -> s mapping
            if (mp2.count(t[i])) {
                // Mapping already exists, check if it matches
                if (mp2[t[i]] != s[i]) {
                    return false;
                }
            }
            else {
                // New character, create its reverse mapping
                mp2[t[i]] = s[i];
            }
        }

        return true;
    }
};