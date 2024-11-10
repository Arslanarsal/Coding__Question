from typing import List

class Solution:
    def insert(self, arr: List[int], num: int) -> None:
        for i in range(31):
            if (num >> i) & 1:
                arr[i] += 1

    def numdele(self, arr: List[int], num: int, a: int) -> int:
        for i in range(31):
            if (num >> i) & 1:
                arr[i] -= 1
                if arr[i] == 0:
                    a &= ~(1 << i)
        return a

    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        arr = [0] * 32
        a = 0
        n = len(nums)
        ans = float('inf')
        j = 0
        
        for i in range(n):
            a |= nums[i]
            self.insert(arr, nums[i])
            while j <= i  and a >= k:
                ans = min(ans, i - j + 1)
                a = self.numdele(arr, nums[j], a)
                j += 1
                
        return -1 if ans == float('inf') else ans
