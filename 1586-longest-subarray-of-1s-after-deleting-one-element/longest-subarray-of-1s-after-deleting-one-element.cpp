class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> arr;
        int ones = 0, largest = 0;
        for (auto it : nums) {
            if (it == 1) 
                ones++;
            else {
                arr.push_back(ones);
                ones = 0;
            }
        }
        arr.push_back(ones);
        for (int i = 0; i + 1 < arr.size(); i++) 
            largest = max(largest, arr[i] + arr[i + 1]);

        largest = max(largest, arr[arr.size()-1]);
        return (arr.size() == 1 && nums.size() == arr[0]) ? nums.size() - 1 : largest;
    }
};