from typing import Dict, List


def dfs(idx: int, course_info: Dict[int, tuple], visited: List[bool], count: int):
    if visited[idx] == 0:   # DISCOVERED
        return False
    elif visited[idx] == 1:   # PROCESSED
        return True

    for prior_course_idx in course_info[idx]:
        visited[idx] = 1
        if dfs(prior_course_idx, course_info, visited, count):
            return True
        visited[idx] = 0

    return False


class Solution:

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        course_info: Dict[int, List[int]] = {i: [] for i in range(numCourses)}
        for course, prior in prerequisites:
            course_info[course].append(prior)

        for course in range(len(course_info)):
            visited: List[bool] = [-1 for _ in range(numCourses)]   # UNDISCOVERED
            if dfs(course, course_info, visited, 0):
                return False

        return True
