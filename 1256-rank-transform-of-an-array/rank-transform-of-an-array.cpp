class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;  
        sort(temp.begin(), temp.end());  
        
        unordered_map<int, int> rankMap;
        int rank = 1;
        
        for (auto it: temp) {
            if (rankMap.find(it) == rankMap.end()) {
                rankMap[it] = rank++;
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rankMap[arr[i]];
        }
        return arr;
    }
};