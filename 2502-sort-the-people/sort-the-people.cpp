class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> heightNamePairs;        
        for(int i = 0; i < names.size(); i++) {
            heightNamePairs.push_back({heights[i], names[i]});
        }
        sort(heightNamePairs.begin(), heightNamePairs.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
        });
        vector<string> ans;
        for(const auto& it : heightNamePairs) {
            ans.push_back(it.second);
        }
        return ans;
    }
};