class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0;
        int minCnt = INT_MAX;
        for(int i=0; i<k; i++){
            if(blocks[i] == 'W'){
                cnt++;
            }
        }
        minCnt = min(minCnt, cnt);
        for(int i=1; i<blocks.size()-k+1; i++){
            cnt = 0;
            for(int j=i; j<i+k; j++){
                if(blocks[j] == 'W'){
                    cnt++;
                }
            }
            minCnt = min(minCnt, cnt);
        }
        return minCnt;
    }
};