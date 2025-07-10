class Solution {
public:
    int maxFreeTime(int e, vector<int>& startTime, vector<int>& endTime) {
        int lenn = startTime.size();

        int cnt = lenn + 1;
        vector<int> arr(cnt, 0);
        arr[0] = startTime[0] - 0;
        for (int i = 1; i < lenn; i++) {
            arr[i] = startTime[i] - endTime[i-1];
        }
        arr[cnt-1] = e - endTime[lenn-1];
        
        int maxi = 0;
        for (int gap : arr) {
            maxi = max(maxi, gap);
        }
        
        vector<int> pre(cnt, 0);
        vector<int> suff(cnt, 0);
        
        pre[0] = arr[0];
        for (int i = 1; i < cnt; i++) {
            pre[i] = max(pre[i-1], arr[i]);
        }
        suff[cnt-1] = arr[cnt-1];
        for (int i = cnt-2; i >= 0; i--) {
            suff[i] = max(suff[i+1], arr[i]);
        }
        
        int res = maxi;
        for (int i = 0; i < lenn; i++) {
            int temp = endTime[i] - startTime[i];
            int t = 0;
            if (i == 0) {
                t = arr[0] + temp + (lenn >= 2 ? arr[1] : 0);
            }
            else if (i == lenn-1) {
                t = arr[lenn-1] + temp + arr[lenn];
            }
            else {
                t = arr[i] + temp + arr[i+1];
            }
            int o1 = 0;
            if (i == 0) {
                if (cnt > 2) {
                    o1 = suff[2];
                }
            }
            else if (i == lenn-1) {
                if (cnt > 2) {
                    o1 = pre[cnt-3];
                }
            }
            else {
                int leftMax = (i-1 >= 0) ? pre[i-1] : 0;
                int rightMax = (i+2 < cnt) ? suff[i+2] : 0;
                o1 = max(leftMax, rightMax);
            }
            int ans = 0;
            if (o1 >= temp) {
                ans = t;
            }
            else {
                ans = t - temp;
            }            
            res = max(res, ans);
        }        
        return res;
    }
};