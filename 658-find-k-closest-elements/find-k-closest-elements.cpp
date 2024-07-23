class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;
        
        for (auto i: arr) {
            int distance = abs(i - x);
            maxHeap.push({distance, i});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<int> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};