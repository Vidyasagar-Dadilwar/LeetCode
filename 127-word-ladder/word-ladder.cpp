class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            auto it = q.front();
            string res = it.first;
            int cnt = it.second;
            q.pop();

            if(res == endWord)
                return cnt;
            
            for(int i=0; i<res.size(); i++){
                char original = res[i];
                for(char j='a'; j<='z'; j++){
                    res[i] = j;

                    if(st.find(res) != st.end()){
                        st.erase(res);
                        q.push({res, cnt+1});
                    }
                }
                res[i] = original;
            }
        }
        return 0;
    }
};