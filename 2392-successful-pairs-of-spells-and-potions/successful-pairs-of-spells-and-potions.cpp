class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> ans(n, 0);
        sort(potions.rbegin(), potions.rend());
        for(int i=0; i<n; i++){
            int l = 0, h = m-1, ind = -1;
            while(l <= h){
                int mid = l + (h - l)/2;
                if((long long)potions[mid]*spells[i] >= success)
                    l = mid + 1;
                else{
                    ind = mid;
                    h = mid - 1;
                }
            }
            if(ind == -1)
                ans[i] = m;
            else 
                ans[i] = ind;
        }
        return ans;
    }
};