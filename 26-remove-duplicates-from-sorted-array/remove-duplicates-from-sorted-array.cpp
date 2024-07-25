class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int cnt = 1; 
        int i = 1;   
        
        while (i < nums.size()) {
            if (nums[i] != nums[i - 1]) {
                nums[cnt] = nums[i];
                cnt++;
            }
            i++;
        }
        
        return cnt;
    }
};