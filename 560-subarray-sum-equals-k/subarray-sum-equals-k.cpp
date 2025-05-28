class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> preSum(n, 0);
        preSum[0] = arr[0];
        
        for(int i=1; i<n; i++)
            preSum[i] = preSum[i-1] + arr[i];
        
        unordered_map<int, int> mp;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(preSum[i] == k)
                 cnt++;
            if(mp.find(preSum[i] - k) != mp.end())
                cnt += mp[preSum[i] - k];
            
            mp[preSum[i]]++;
        }
        return cnt;
    }
};