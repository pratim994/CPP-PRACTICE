#leetcode solution for prefix gcd computation in python 15/7/26

import sys

class Solution:

    def prefixgcd(self, nums: list[int]) -> int:

        n = len(nums)

        mx = [nums[0]]*n

        pgcd = [nums[0]]*n

        for i in range(1,n):

            mx[i] = max(mx[i-1],nums[i])

            pgcd = gcd(mx[i],gcd[i])

        pgcd.sort()
        res =0

        for i in range(n//2):
            res += gcd(pgcd[i],pgcd[n-i-1])

        return res
        

