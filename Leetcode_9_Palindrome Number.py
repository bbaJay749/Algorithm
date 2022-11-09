from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}

        for i, num in enumerate(nums):
            complement = target - num
            if complement in table:
                return [i, table[complement]]
            else:
                table[num] = i


''' stupid way

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numsLen = len(nums)
        for idx1 in range(0, numsLen):
            for idx2 in range(idx1 + 1, numsLen):
                if nums[idx1] + nums[idx2] == target:
                    return [idx1, idx2]
'''