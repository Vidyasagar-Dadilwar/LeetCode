class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> binary(n);
        string bstring = binary.to_string();
        reverse(bstring.begin(), bstring.end());
        auto ans = stoul(bstring, nullptr, 2);
        return ans;
    }
};