class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        auto isPalindrome = [&](int left, int right) {
            while (left < right) {
                if (s[left] != s[right]) {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        };

        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(left + 1, right) || isPalindrome(left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};