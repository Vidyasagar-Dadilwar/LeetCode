class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> binary(n);
        string bstring = binary.to_string();

        int cnt = 0;
        for(auto i: bstring){
            if(i == '1')
                cnt++;
        }
        return cnt;
    }
};