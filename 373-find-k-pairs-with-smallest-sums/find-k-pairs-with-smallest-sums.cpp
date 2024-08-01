class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        vector<vector<int>>ans;

        for(auto i: nums1)
            pq.push({i+nums2[0], 0});
        
        while(!pq.empty() && k--){
            auto [sum, pos] = pq.top();
            pq.pop();
            ans.push_back({sum-nums2[pos], nums2[pos]});
            if(pos < nums2.size()-1){
                pq.push({sum-nums2[pos] + nums2[pos+1], pos+1});
            }
        }
        return ans;
    }
};