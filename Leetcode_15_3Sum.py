from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # Get rid of multiple 0s. only 3 of 0s are fine.
        if nums.count(0) >= 3:
            for _ in range(nums.count(0)-3):
                nums.remove(0)
        # Get the input sorted in ascending order.
        nums.sort()

        result = list()
        for first_idx in range(len(nums)-2):
            second_idx = first_idx + 1
            third_idx = len(nums) - 1

            while (second_idx != third_idx):
                if nums[first_idx] + nums[second_idx] + nums[third_idx] < 0:
                    second_idx += 1
                elif nums[first_idx] + nums[second_idx] + nums[third_idx] > 0:
                    third_idx -= 1
                elif nums[first_idx] + nums[second_idx] + nums[third_idx] == 0:
                    result.append([nums[first_idx], nums[second_idx], nums[third_idx]])
                    third_idx -= 1

        return list(set([tuple(item) for item in result]))  # delete duplicate triplets.
