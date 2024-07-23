class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // for (int i = 0; i < points.size(); i++) {
        //     int x = points[i][0], y = points[i][1];
        //     minHeap.push({x * x + y * y, i});
        // }
        
        // vector<vector<int>> res;
        // for (int i = 0; i < k; i++) {
        //     auto it = minHeap.top();
        //     res.push_back(points[it.second]);
        //     minHeap.pop();
        // }
        // return res;



        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxHeap.push({dist, {points[i][0], points[i][1]}});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            auto it = maxHeap.top();
            maxHeap.pop();
            ans.push_back({it.second.first, it.second.second});
        }
        return ans;
    }
};