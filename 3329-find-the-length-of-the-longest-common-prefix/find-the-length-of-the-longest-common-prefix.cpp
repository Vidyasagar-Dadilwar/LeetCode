class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int>mp;
        for(auto i: arr1){
            string s = to_string(i);
            string temp = "";
            for(auto c: s){
                temp += c;
                mp[temp]++;
            }
        }

        int maxLen = 0;
        for(auto i: arr2){
            string s = to_string(i);
            string temp = "";
            for(auto c: s){
                temp += c;
                if(mp.find(temp) != mp.end()){
                    maxLen = max(maxLen, static_cast<int>(temp.size()));
                }
            }
        }
        return maxLen;
    }
};