from typing import List


class Solution:

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = []

        temp = 1
        # 1st num * all nums except itself
        for i in range(len(nums)):
            result.append(temp)
            temp *= nums[i]

        temp = 1
        # last num * all nums except itself
        for i in range(len(nums) - 1, -1, -1):
            result[i] *= temp  # save right away.
            temp *= nums[i]

        return result


''' 시간초과
support_matrix라는 필터를 활용하는 방식..

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1] * len(nums)

        for idx, num in enumerate(nums):
            support_matrix = [num] * len(nums)
            support_matrix[idx] = 1
            result = np.multiply(result, support_matrix)

        return result
'''
