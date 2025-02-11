class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i = s.find(part);
        while(i>=0 && i<s.size()){
            s.erase(i, part.size());
            i = s.find(part);
        }
        return s;
    }
};