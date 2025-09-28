class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        while(nums.size() > 2 && nums[0] >= nums[1] + nums[2])
            nums.erase(nums.begin());
        return nums.size() < 3 ? 0 : nums[0] + nums[1] + nums[2];
    }
};