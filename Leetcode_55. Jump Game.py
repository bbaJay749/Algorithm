from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        if min(nums[:-1]) >= 1:
            return True

        reachable_steps = nums[:nums[0]+1]
        last_idx = len(nums) -1
        start = 1
        end = nums[0] + 1

        while(True):
            for idx, step in enumerate(reachable_steps[start:end]):
                reachable_steps[start+idx] = start + idx + step

            if max(reachable_steps) >= last_idx:
                return True

            if (start==len(reachable_steps)) and (end == max(reachable_steps) + 1):
                return False

            start = len(reachable_steps)
            end = max(reachable_steps) + 1
            reachable_steps = nums[:max(reachable_steps) + 1]