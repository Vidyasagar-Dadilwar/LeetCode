class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = 10**9 + 7
        
        def power(base, exp):
            if exp == 0:
                return 1
            temp = power(base, exp // 2)
            if exp % 2 == 0:
                return (temp * temp) % MOD
            else:
                return (base * temp * temp) % MOD

        even_count = (n + 1) // 2  
        odd_count = n // 2         

        even = power(5, even_count)
        odd = power(4, odd_count)

        return (even * odd) % MOD
