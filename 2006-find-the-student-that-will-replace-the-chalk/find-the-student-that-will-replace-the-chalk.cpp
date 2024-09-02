#include <numeric>
#include <vector>

class Solution {
public:
    int chalkReplacer(std::vector<int>& chalk, int k) {
        unsigned long long totalChalk = std::accumulate(chalk.begin(), chalk.end(), 0ULL); // Use 0ULL for unsigned long long
        k = k % totalChalk;
        int ans = 0;
        for(int i = 0; i < chalk.size(); i++){
            k -= chalk[i];
            if(k < 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};