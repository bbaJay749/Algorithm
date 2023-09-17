from typing import List, Tuple


class Solution:
    dirs: List[List[int]] = [[1, 0], [-1, 0], [0, 1], [0, -1]]

    def dfs(self, heights: List[List[int]], cell_loc: Tuple[int, int], result: List[List[int]]):
        if [cell_loc[0], cell_loc[1]] not in result:
            result.append([cell_loc[0], cell_loc[1]])
        else:
            return

        for dir in self.dirs:
            if (0 <= cell_loc[0] + dir[0] < self.n) and (0 <= cell_loc[1] + dir[1] < self.m):
                if heights[cell_loc[0]][cell_loc[1]] <= heights[cell_loc[0]+dir[0]][cell_loc[1]+dir[1]]:
                    self.dfs(heights, (cell_loc[0]+dir[0], cell_loc[1]+dir[1]), result)

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.m: int = len(heights[0])
        self.n: int = len(heights)
        A_result: List[List[int]] = []
        P_result: List[List[int]] = []

        for i in range(0, self.n):
            self.dfs(heights, (i, 0), P_result)
            self.dfs(heights, (i, self.m-1), A_result)

        for i in range(0, self.m):
            self.dfs(heights, (0, i), P_result)
            self.dfs(heights, (self.n-1, i), A_result)

        return [cell for cell in A_result if cell in P_result]
