class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int candidate = -1, cnt = 0;
        for(auto i: nums){
            if(cnt == 0)
                candidate = i;
            cnt += (i == candidate) ? 1 : -1;
        }
        int total = 0;
        for(auto i: nums)
            if(i == candidate) 
                total++;
        int pre = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == candidate) 
                pre++;
            if (pre * 2 > (i + 1) && (total - pre) * 2 > (n - i - 1)) 
                return i;
        }
        return -1;
    }
};