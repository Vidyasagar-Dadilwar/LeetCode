class Solution {
public:
    bool areNumbersAscending(string s) {
        int prevNumber = -1, i = 0;

        while (i < s.size()) {
            while (i < s.size() && !isdigit(s[i])) {
                i++;
            }
            if (i >= s.size()) break;

            int currentNumber = 0;
            while (i < s.size() && isdigit(s[i])) {
                currentNumber = currentNumber * 10 + (s[i] - '0');
                i++;
            }

            if (currentNumber <= prevNumber) {
                return false;
            }
            prevNumber = currentNumber;
        }
        return true;
    }
};
