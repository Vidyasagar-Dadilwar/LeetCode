class Solution {
public:
    bool dist(string w1, string w2) {
        if (w1.size() != w2.size()) 
            return false;  
        int cnt = 0;
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i]) {
                cnt++;
                if (cnt > 1)
                    return false;
            }
        }
        return cnt == 1;
    }

    bool solve(vector<string>& words, vector<int>& groups, int i, int j) {
        return groups[i] != groups[j] && dist(words[i], words[j]);
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), helper(n, -1);
        int maxLength = 1, lastIndex = 0;
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (solve(words, groups, i, j)) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        helper[i] = j;
                    }
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                lastIndex = i;
            }
        }

        while (lastIndex != -1 && lastIndex < words.size() && lastIndex < helper.size()) {
            ans.push_back(words[lastIndex]);
            lastIndex = helper[lastIndex];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};