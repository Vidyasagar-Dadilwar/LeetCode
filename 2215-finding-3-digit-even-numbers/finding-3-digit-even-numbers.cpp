class Solution {
public:
    bool canForm(int i, unordered_map<int, int> mp){
        while(i>0){
            int t = i % 10;
            if(mp[t] == 0)
                return false;
            mp[t]--;
            i = i / 10;
        }
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> arr;
        unordered_map<int, int> mp;
        for(auto it: digits)
            mp[it]++;

        for(int i=100; i<999; i+=2){
            if(canForm(i, mp)){
                arr.push_back(i);
            }
        }
        return arr;
    }
};