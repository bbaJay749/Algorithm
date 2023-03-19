from typing import List


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        insert_interval = [None, None]

        if len(intervals) == 0:
            return [newInterval]

        for idx, interval in enumerate(intervals):
            # Find the first element of insert_interval
            if insert_interval[0] is None:
                if newInterval[0] < interval[0]:
                    insert_interval[0] = newInterval[0]
                if interval[0] <= newInterval[0] and newInterval[0] <= interval[1]:
                    insert_interval[0] = interval[0]
                elif interval[1] < newInterval[0]:
                    if idx + 1 == len(intervals) or newInterval[0] < intervals[idx + 1][0]:
                        insert_interval[0] = newInterval[0]

            # Find the second element of insert_interval
            if insert_interval[0] is not None and insert_interval[1] is None:
                if newInterval[1] < interval[0]:
                    insert_interval[1] = newInterval[1]
                elif interval[0] <= newInterval[1] and newInterval[1] <= interval[1]:
                    insert_interval[1] = interval[1]
                elif interval[1] < newInterval[1]:
                    if idx + 1 == len(intervals) or newInterval[1] < intervals[idx + 1][0]:
                        insert_interval[1] = newInterval[1]

        # Get all elements to remove.
        remove_list = []
        for idx, interval in enumerate(intervals):
            if interval[0] <= insert_interval[0]:
                if interval[1] < insert_interval[0]:
                    pass
                else:
                    remove_list.append(interval)
            elif interval[1] <= insert_interval[1]:
                remove_list.append(interval)

        # Remove unnecessary elements from input.
        for remove_interval in remove_list:
            intervals.remove(remove_interval)

        # Append interval to insert and sort by first element.
        intervals.append(insert_interval)
        intervals.sort(key=lambda x: x[0])

        return intervals
