#include<bits/stdc++.h>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq_map;
        for(int num : nums) {
            freq_map[num]++;
        }
        priority_queue<pair<int, int>> max_heap;
        for(auto it = freq_map.begin(); it != freq_map.end(); it++) {
            max_heap.push({it->second, it->first});
            // if(max_heap.size() > freq_map.size() - k) {
            //     nums.push_back(it->first);
            // }
        }
        vector<int> ans;
        while(k--) {
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return ans;
    }
};
