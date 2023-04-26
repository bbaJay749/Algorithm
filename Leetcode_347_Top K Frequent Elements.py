from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Get a empty Dict to save value_count.
        value_count = {}
        for num in nums:
            if num in value_count.keys():
                value_count[num] += 1
            else:
                value_count[num] = 1

        # Sort dict `value_count`. use dict.value() as key. descending order.
        value_count = sorted(value_count.items(), key=lambda x: x[1], reverse=True)

        # Get k most frequent elements.
        result = []
        for idx in range(k):
            result.append(value_count[idx][0])

        return result
