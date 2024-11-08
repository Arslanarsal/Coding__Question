from typing import List

class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        ans = []
        n = len(nums)
        temp = 0
        for i in nums:
            temp = temp ^ i
        k = (1 <<maximumBit) -1    
        for i in range(n):
            num = k
            for j in range(maximumBit):
                if (temp >> j) & 1:
                    num = num & ~(1 << j)
                else:
                    num = num | (1<<j)    
            ans.append(num)
            temp = temp ^ nums[n-i-1]
        # ans.reverse()
        return ans   