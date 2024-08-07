#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const vector<string> belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> belowHundred = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string convertLessThanThousand(int num) {
        string result;
        if (num >= 100) {
            result += belowTwenty[num / 100] + " Hundred";
            num %= 100;
            if (num > 0) result += " ";
        }
        if (num >= 20) {
            result += belowHundred[num / 10];
            num %= 10;
            if (num > 0) result += " " + belowTwenty[num];
        } else if (num > 0) {
            result += belowTwenty[num];
        }
        return result;
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string words;
        int thousand = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                string part = convertLessThanThousand(num % 1000);
                if (thousand > 0) part += " " + thousands[thousand];
                if (!words.empty()) part += " ";
                words = part + words;
            }
            num /= 1000;
            thousand++;
        }

        if (!words.empty()) {
            while (words.front() == ' ') words.erase(words.begin());
            while (words.back() == ' ') words.pop_back();
        }
        return words;
    }
};