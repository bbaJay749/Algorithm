from typing import List


class Solution:
    """
    Kadane's Algorithm, Largest Sum Contiguous Subarray, LSCS
    https://siahn95.tistory.com/entry/AlgorithmLeetCodeEasyPython-53-Maximum-Subarray
    """

    def maxSubArray(self, nums: List[int]) -> int:
        local_max_sum = global_max_sum = nums[0]

        for num in nums[1:]:
            local_max_sum = max(local_max_sum + num, num)
            global_max_sum = max(global_max_sum, local_max_sum)

        return global_max_sum
