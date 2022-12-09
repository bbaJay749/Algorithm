from typing import List


class Solution:

    def containsDuplicate(self, nums: List[int]) -> bool:
        check_duplicate = set()

        for num in nums:
            if num in check_duplicate:
                return True
            else:
                check_duplicate.add(num)

        return False
    