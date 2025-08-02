class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int mini = INT_MAX;
        for(int i=0; i<basket1.size(); i++){
            mp[basket1[i]]++;
            mp[basket2[i]]--;
            mini = min({mini, basket1[i], basket2[i]});
        }
               
        long long res = 0;
        for(auto it: mp){
            int ele = it.first, freq = it.second;
            if(freq%2 == 1) 
                return -1;
            res += abs(freq);
        }

        vector<int> swapList;
        for(auto& [fruit, diff] : mp) {
            for(int i = 0; i < abs(diff) / 2; i++) {
                swapList.push_back(fruit);
            }
        }

        sort(swapList.begin(), swapList.end());

        long long ans = 0, doubleMin = 2LL * mini;
        int half = swapList.size() / 2;

        for(int i = 0; i < half; i++) {
            ans += min((long long)swapList[i], doubleMin);
        }

        return ans;        
    }
};