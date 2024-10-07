class Solution {
public:
    void sortColors(vector<int>& nums) {
        make_heap(nums.begin(),nums.end());
        sort_heap(nums.begin(),nums.end());
    }
};