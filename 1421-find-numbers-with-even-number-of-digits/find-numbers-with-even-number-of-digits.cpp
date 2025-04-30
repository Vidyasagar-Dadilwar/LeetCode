class Solution {
public:
    bool even(int num){
        int t = (num < 0) ? num * -1 : num;
        t = (int)(log10(t)) + 1;
        return t%2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto num: nums){
            if(even(num))
                cnt++;
        }
        return cnt;
    }
};