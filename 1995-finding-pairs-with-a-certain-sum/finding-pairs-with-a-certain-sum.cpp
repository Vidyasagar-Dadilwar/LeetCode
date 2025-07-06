class FindSumPairs {
    unordered_map<int, int> freq1, freq2;
    vector<int> vnums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(const int& num : nums1){
            freq1[num]++;
        }
        for(const int& num : nums2){
            freq2[num]++;
        }
        vnums2 = nums2;
    }
    
    void add(int index, int val) {
        int cur_val = vnums2[index];

        freq2[cur_val]--;
        vnums2[index] += val;
        freq2[cur_val + val]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(const auto& [val1, cnt1] : freq1){
            if (freq2.count(tot - val1) > 0){
                res += cnt1 * freq2[tot - val1];
            }
        }
        
        return res;
    }
};