class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> mp;
        vector<int> ans;
        int n = s.size();
        for(int i=0; i<n; i++)
            mp[s[i]].push_back(i);
        int st = 0, en = 0;
        for(int i=0; i<n; i++){
            int last = mp[s[i]].back();
            en = max(en, last);
            if(i == en){
                ans.push_back(en-st+1);
                st = i+1;
            }
        }
        return ans;
    }
};