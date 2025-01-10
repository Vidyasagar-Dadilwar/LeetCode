class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<char, int> maxFreq;
        for(auto word: words2){
            unordered_map<char, int> mp;
            for(auto i: word){
                mp[i]++;
            }
            for(auto it: mp){
                maxFreq[it.first] = max(maxFreq[it.first], it.second);
            }
        }

        int flag = 1;
        for(auto word: words1){
            flag=1;
            unordered_map<char, int> freq;
            for(auto c: word)
                freq[c]++;
            
            for(auto it: maxFreq){
                if(it.second > freq[it.first]){
                    flag = 0;
                    break;
                }
            }
            if(flag)
                ans.push_back(word);
        }
        return ans;
    }
};