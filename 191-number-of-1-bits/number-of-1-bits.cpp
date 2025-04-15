class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> binary(n);
        string bstring = binary.to_string();

        int cnt = count(bstring.begin(), bstring.end(), '1');
        return cnt;
    }
};