class Solution {
public:
    vector<string> convertString(string s){
        vector<string> words;
        istringstream iss(s);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> w1 = convertString(s1);
        vector<string> w2 = convertString(s2);

        unordered_map<string, int> mp;
        for(auto i: w1){
            mp[i]++;
        }
        for(auto i: w2){
            mp[i]++;
        }
        vector<string>ans;
        for(auto it: mp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};