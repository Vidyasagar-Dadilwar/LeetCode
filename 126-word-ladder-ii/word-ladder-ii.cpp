class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (wordSet.find(endWord) == wordSet.end()) return result;

        unordered_map<string, vector<string>> parentMap;
        unordered_map<string, int> level;
        queue<string> q;

        q.push(beginWord);
        level[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int currLevel = level[word];

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (wordSet.find(temp) != wordSet.end()) {
                        if (!level.count(temp)) {
                            level[temp] = currLevel + 1;
                            q.push(temp);
                            parentMap[temp].push_back(word);
                        } else if (level[temp] == currLevel + 1) {
                            parentMap[temp].push_back(word);
                        }
                    }
                }
            }
        }

        // Backtrack from endWord to beginWord
        vector<string> path;
        dfs(endWord, beginWord, parentMap, path, result);
        return result;
    }

    void dfs(string word, string& beginWord,
             unordered_map<string, vector<string>>& parentMap,
             vector<string>& path, vector<vector<string>>& result) {
        path.push_back(word);
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
        } else {
            for (string parent : parentMap[word]) {
                dfs(parent, beginWord, parentMap, path, result);
            }
        }
        path.pop_back();
    }
};