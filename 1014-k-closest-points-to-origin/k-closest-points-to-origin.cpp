class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            minHeap.push({x * x + y * y, i});
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            auto it = minHeap.top();
            res.push_back(points[it.second]);
            minHeap.pop();
        }
        return res;
    }
};