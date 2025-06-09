class Solution {
public:
    long long countPrefix(long long n, long long prefix) {
        long long curr = prefix, next = prefix + 1, count = 0;
        while (curr <= n) {
            count += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1;
        while (k > 0) {
            long long count = countPrefix(n, curr);
            if (count <= k) {
                curr++;
                k -= count;
            } 
            else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};