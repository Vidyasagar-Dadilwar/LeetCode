class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>mini;
        for(int i=0; i<n; i++){
            int num = (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
            num += ((timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0')) * 60;
            mini.push_back(num);
        }
        sort(mini.begin(), mini.end());
        mini.push_back(mini[0]+1440);
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            if(ans == 0)
                return ans;
            ans = min(ans, abs(mini[i]-mini[i+1]));
        }
        return ans;
    }
};