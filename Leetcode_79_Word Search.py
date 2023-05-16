from typing import List


class Solution:

    def find_way(self, board: List[List[str]], word: str, row_idx: int, col_idx: int):
        if len(word) == 0:
            return True
        if row_idx < 0 or row_idx >= len(board) or col_idx < 0 or col_idx >= len(board[0]):
            return False

        if board[row_idx][col_idx] == word[0]:
            board[row_idx][col_idx] = None
            if self.find_way(board, word[1:], row_idx+1, col_idx) or \
               self.find_way(board, word[1:], row_idx-1, col_idx) or \
               self.find_way(board, word[1:], row_idx, col_idx+1) or \
               self.find_way(board, word[1:], row_idx, col_idx-1):
               return True
            board[row_idx][col_idx] = word[0]
        return False

    def exist(self, board: List[List[str]], word: str) -> bool:
        for row_idx, line in enumerate(board):
            for col_idx, _ in enumerate(line):
                if self.find_way(board, word, row_idx, col_idx):
                    return True
        return False
