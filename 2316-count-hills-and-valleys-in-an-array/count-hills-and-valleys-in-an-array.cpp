class Solution {
public:
    int countHillValley(vector<int>& arr) {
        int s = arr[0], e = arr[1], cnt = 0;

        for(int i=2; i<arr.size(); i++){
            int n = arr[i];
            bool hill = s > e && e < n;
            bool valley = s < e && e > n;

            if(hill || valley){
                cnt++;
                s = e;
            }
            e = n;
        }
        return cnt;
    }
};