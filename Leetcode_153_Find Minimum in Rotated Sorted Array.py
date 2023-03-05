from typing import List


def divideAndConquer(nums: List[int]):
    numsLen = len(nums)

    if numsLen == 1:
        return nums[0]
    if numsLen == 2:
        return nums[0] if nums[0] < nums[1] else nums[1]

    if numsLen % 2 == 0:
        if nums[numsLen // 2 - 1] < nums[-1]:
            return divideAndConquer(nums[:numsLen // 2])
        else:
            return divideAndConquer(nums[numsLen // 2:])
    else:
        if nums[numsLen // 2] < nums[-1]:
            return divideAndConquer(nums[:numsLen // 2 + 1])
        else:
            return divideAndConquer(nums[numsLen // 2 + 1:])


class Solution:

    def findMin(self, nums: List[int]) -> int:
        return divideAndConquer(nums)
