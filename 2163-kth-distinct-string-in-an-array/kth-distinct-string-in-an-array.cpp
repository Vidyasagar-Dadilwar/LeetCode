class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;
        for (const auto& str : arr) {
            mp[str]++;
        }
        string kString = "";
        for(auto a: arr){
            if (mp[a] == 1) {
                k--;
                if (k == 0) {
                    kString = a;
                }
            }
        }
        return kString;
    }
};