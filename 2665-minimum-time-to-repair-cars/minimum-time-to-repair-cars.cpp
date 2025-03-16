class Solution {
public:
    bool isPossible(vector<int>& ranks, int& cars, long long m){
        long long t = 0;
        for(auto r: ranks){
            long long n2 = m/r;
            long long cnt = floor(sqrt(n2));
            t += cnt;
        }
        return t >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1e14;
        while(l<r){
            long long m = l+(r-l)/2;
            if(isPossible(ranks, cars, m))
                r = m;
            else
                l = m+1;
        }
        return l;
    }
};