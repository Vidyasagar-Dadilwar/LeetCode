class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;
        for (const auto& str : arr) {
            mp[str]++;
        }
        for(auto i: arr){
            if(mp[i]==1 && k==1){
                return i;
            }
            else if(mp[i]==1){
                k--;
            }
        }
        return "";
    }
};