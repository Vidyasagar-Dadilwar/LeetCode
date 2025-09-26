class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        for(auto it: nums1)     arr.push_back(it);
        for(auto it: nums2)     arr.push_back(it);
        sort(arr.begin(), arr.end());
        if(arr.size()%2 == 0)
            return ((1.0)*arr[arr.size()/2-1] + (1.0)*arr[arr.size()/2])/2.0;
        return arr[arr.size()/2];
    }
};