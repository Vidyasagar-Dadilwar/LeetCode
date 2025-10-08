class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> ans(n, 0);
        sort(potions.begin(), potions.end());
        
        for(int i = 0; i < n; i++) {
            int l = 0, h = m - 1, idx = m;
            while(l <= h) {
                int mid = l + (h - l) / 2;
                if((long long)potions[mid] * spells[i] >= success) {
                    idx = mid;   
                    h = mid - 1; 
                } 
                else 
                    l = mid + 1; 
            }
            ans[i] = m - idx;
        }
        return ans;
    }
};