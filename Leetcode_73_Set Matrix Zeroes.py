from typing import List


class Solution:
    '''
    required a constant space solution.
    '''

    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        M = len(matrix)
        N = len(matrix[0])

        for row in range(M):
            for col in range(N):
                if matrix[row][col] == 0:
                    for i in range(M):
                        if matrix[i][col] != 0:
                            matrix[i][col] = "zero"
                    for j in range(N):
                        if matrix[row][j] != 0:
                            matrix[row][j] = "zero"

        for i in range(M):
            for j in range(N):
                if matrix[i][j] == "zero":
                    matrix[i][j] = 0
