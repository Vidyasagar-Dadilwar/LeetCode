class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        string maxStr = "";
        if(numFriends == 1)
            return word;
            
        for (int i = 0; i < n; ++i) {
            string suffix = word.substr(i);
            if (suffix > maxStr) {
                maxStr = suffix;
            }
        }

        string best = "";
        int maxLen = n - numFriends + 1;
        for (int len = 1; len <= maxLen && len <= (int)maxStr.size(); ++len) {
            string sub = maxStr.substr(0, len);
            if (sub > best) {
                best = sub;
            }
        }

        return best;
    }
};
