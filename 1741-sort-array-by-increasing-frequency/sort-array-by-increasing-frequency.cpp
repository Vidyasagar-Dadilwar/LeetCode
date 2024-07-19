class Solution {
public:
    struct comparator{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) 
                return a.second > b.second;
            return a.first < b.first;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(int i: nums){
            mp[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> min_heap;
        for(auto it: mp){
            min_heap.push({it.first, it.second});
        }   
        vector<int>ans;
        while(!min_heap.empty()){
            auto it = min_heap.top();
            while(it.second){
                ans.push_back(it.first);
                it.second--;
            }
            min_heap.pop();
        }
        return ans;
    }
};