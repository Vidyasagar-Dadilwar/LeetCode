class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = 0, minDiff = INT_MAX;

        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int curr = nums[i] + nums[l] + nums[r];
                int diff = abs(curr - target);

                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = curr;
                }
                if (curr < target)
                    l++;
                else
                    r--;
            }
        }
        return closestSum;
    }
};