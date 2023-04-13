from typing import List


class Solution:
    class Direction:
        def __init__(self, data, next=None):
            self.data = data
            self.next = next

    Right = Direction(data=(0, 1))
    Down = Direction(data=(1, 0))
    Left = Direction(data=(0, -1))
    Up = Direction(data=(-1, 0))

    Right.next = Down
    Down.next = Left
    Left.next = Up
    Up.next = Right

    def DFS(self, matrix: List[List[int]], visited: List[List[bool]], index: tuple, Dir: Direction):
        visited[index[0]][index[1]] = True
        self.result.append(matrix[index[0]][index[1]])

        row = index[0] + Dir.data[0]
        col = index[1] + Dir.data[1]
        if (0 <= row) and (0 <= col):
            if (row < len(matrix)) and (col < len(matrix[0])):
                if not visited[row][col]:
                    self.DFS(matrix, visited, (row, col), Dir)
                    return

        row = index[0] + Dir.next.data[0]
        col = index[1] + Dir.next.data[1]
        if (0 <= row) and (0 <= col):
            if (row < len(matrix)) and (col < len(matrix[0])):
                if not visited[row][col]:
                    self.DFS(matrix, visited, (row, col), Dir.next)
                    return

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        visited = [[False] * len(matrix[0]) for _ in range(len(matrix))]
        self.result = list()
        self.DFS(matrix, visited, (0, 0), self.Right)
        return self.result
