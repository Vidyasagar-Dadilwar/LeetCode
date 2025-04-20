class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(auto &it: answers){
            mp[it]++;
        }
        int ans = 0;
        for(auto it: mp){
            int x = it.second, y = it.first + 1, tmp;
            tmp = x/y;
            if(x%y > 0)
                tmp++;
            ans += tmp*y;
        }
        return ans;
    }
};