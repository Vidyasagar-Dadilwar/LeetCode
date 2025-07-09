class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> diff;
        diff.push_back(startTime.front());
        for(int i=1; i<startTime.size(); i++)
            diff.push_back(startTime[i]-endTime[i-1]);
        diff.push_back(eventTime - endTime.back());

        int i=0, j=0, sum=0, maxi=0;
        while(j<diff.size()){
            sum += diff[j];
            if(j-i+1 > k+1)
                sum -= diff[i++];
            maxi = max(maxi, sum);
            j++;
        }
        return maxi;
    }
};
