#include <climits>

using ll = long long;
constexpr int aMax = 100001;
ll differences[aMax];

class Solution {
    public : ll minimumDifference(const std::vector<int>& nums) {
        const int n = nums.size() / 3;

        std::priority_queue<ll, std::vector<ll>, std::greater<ll>> rq(nums.begin() + 2 * n, nums.end());
        ll rSum = std::accumulate(nums.begin() + n * 2, nums.end(), 0LL, [&](ll s, int x) { return s += x; });

        std::priority_queue<ll> lq(nums.begin(), nums.begin() + n);
        ll lSum = std::accumulate(nums.begin(), nums.begin() + n,   0LL, [&](ll s, int x) { return s += x; });

        std::fill(differences, differences + aMax, LLONG_MAX);

        for (ll i = n; i <= n * 2; ++i) {
            differences[i-n] = lSum;

            if (nums[i] < lq.top()) {                
                lSum += nums[i] - lq.top(); lq.pop();
                lq.push(nums[i]);
            }
        }

        for (ll i = n * 2 - 1; i >= n - 1; --i) {
            differences[i-n+1] -= rSum;

            if (nums[i] > rq.top()) { 
                rSum += nums[i] - rq.top(); rq.pop();
                rq.push(nums[i]);
            }
        }

        return *std::min_element(differences, differences + aMax);
    }
};