class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int k = n - numFriends + 1;
        int i = 0, j = 1;

        if(numFriends == 1)
            return word;
            
        while (j < n) {
            int len = 0;
            while (j + len < n && word[i + len] == word[j + len]) {
                len++;
            }

            if (j + len < n && word[i + len] < word[j + len]) {
                i = j;
                j = i + 1;
            } 
            else {
                j = j + len + 1;
            }
        }

        string res = "";
        for (int len = 1; len <= k && i + len <= n; ++len) {
            string sub = word.substr(i, len);
            res = max(res, sub);
        }

        return res;
    }
};