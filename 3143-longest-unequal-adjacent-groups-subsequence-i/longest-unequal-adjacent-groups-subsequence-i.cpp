class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int o=0, z=0;
        int flag = 0;
        for(auto it: groups){
            if(it == flag){
                z++;
                flag = !flag;
            }
        }
        flag = 1;
        for(auto it: groups){
            if(it == flag){
                o++;
                flag = !flag;
            }
        }
        flag = (z > o) ? 0 : 1;
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            if(groups[i] == flag){
                ans.push_back(words[i]);
                flag = !flag;
            }
        }
        return ans;
    }
};