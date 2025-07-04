class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> len = {1};
        for(auto it: operations){
            if(len.back() > k)
                break;
            len.push_back(2 * len.back());
        }

        int j=0;
        for(int i=len.size()-1; i > 0; i--){
            long long half = len[i-1];
            if(k > half){
                k -= half;
                if(operations[i-1] == 1)
                    j = (++j)%26;
            }
        }
        return (char)(j + 'a');
    }
};