class Solution {
public:
    string minWindow(std::string s, std::string t) {
        if (t.size() > s.size()) {
            return "";
        }
        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c]++;
        }
        int l = 0, r = 0, minLen = INT_MAX, start = 0;
        int required = t.size();        
        while (r < s.size()) {
            if (mp[s[r]] > 0) {
                required--;
            }
            mp[s[r]]--;
            r++;
            while (required == 0) {
                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    required++;
                }
                l++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};