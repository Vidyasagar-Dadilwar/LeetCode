class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        replace(possible.begin(), possible.end(), 0, -1);
        vector<int>sum(possible.size(),0);
        sum[0]=possible[0];
        for(int i=1; i<possible.size(); i++){
            sum[i]=sum[i-1]+possible[i];
        }
        for(int i=0; i<sum.size()-1; i++){
            int t1 = sum[i];
            int t2 = sum[sum.size()-1] - sum[i];
            if(t1>t2)
                return i+1;
        }
        return -1;
    }
};