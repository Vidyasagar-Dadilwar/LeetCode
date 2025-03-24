class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> arr;
        arr.push_back(meetings[0]);
        for(int i=1; i<meetings.size(); i++){
            vector<int>&last = arr.back();
            if (meetings[i][0] <= last[1]) { 
                last[1] = max(last[1], meetings[i][1]); 
            } 
            else {
                arr.push_back(meetings[i]); 
            }
        }
        int ans = 0;
        if (arr[0][0] > 1) {
            ans += arr[0][0] - 1;
        }
        for(int i=1; i<arr.size(); i++){
            ans += (arr[i][0] - arr[i-1][1] - 1);
        }
        if (arr.back()[1] < days) {
            ans += days - arr.back()[1];
        }
        return ans;
    }
};