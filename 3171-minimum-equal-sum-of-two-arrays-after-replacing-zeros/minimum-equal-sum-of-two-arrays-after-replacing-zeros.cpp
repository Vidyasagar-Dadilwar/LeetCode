class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        long long s1 = 0, s2 = 0, z1 = 0, z2 = 0;
        for (int num : nums1) {
            if (num == 0) 
                z1++;
            else 
                s1 += num;
        }
        for (int num : nums2) {
            if (num == 0) 
                z2++;
            else 
                s2 += num;
        }
        long long mini1 = s1 + z1;
        long long mini2 = s2 + z2;
        if ((z1 == 0 && mini2 > s1) || (z2 == 0 && mini1 > s2))
            return -1;

        return max(mini1, mini2);
    }
};