class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;

        for(auto it: s)
            mp[it]++;
        
        int maxOdd = 0, maxEven = 100;

        for(auto it: mp){
            if(it.second%2 == 0)
                maxEven = min(maxEven, it.second);
            else
                maxOdd = max(maxOdd, it.second);
        }
        return maxOdd - maxEven;
    }
};