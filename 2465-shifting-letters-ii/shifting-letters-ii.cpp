class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shift(n + 1, 0);
        for (auto& it : shifts) {
            int start = it[0];
            int end = it[1];
            int dir = it[2];
            shift[start] += (dir == 1 ? 1 : -1);
            shift[end + 1] -= (dir == 1 ? 1 : -1);
        }        
        int cumStart = 0;
        for (int i = 0; i < n; i++) {
            cumStart += shift[i];
            int newChar = (s[i] - 'a' + cumStart) % 26;
            if (newChar < 0) newChar += 26; 
            s[i] = 'a' + newChar;
        }
        return s;
    }
};
