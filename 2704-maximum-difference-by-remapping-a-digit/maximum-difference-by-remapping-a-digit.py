class Solution:
    def minMaxDifference(self, num: int) -> int:
        digits = list(map(int, str(num)))

        for d in digits:
            if d != 9:
                max_digits = [9 if x == d else x for x in digits]
                break
        else:
            max_digits = digits[:] 

        for d in digits:
            if d != 0:
                min_digits = [0 if x == d else x for x in digits]
                break
        else:
            min_digits = digits[:]

        max_num = int(''.join(map(str, max_digits)))
        min_num = int(''.join(map(str, min_digits)))

        return max_num - min_num