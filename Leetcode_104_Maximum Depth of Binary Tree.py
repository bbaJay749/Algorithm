from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:

        def dfs(current: Optional[TreeNode], temp_depth: int, depth: int):
            temp_depth += 1
            if temp_depth > depth:
                depth = temp_depth

            if current.left:
                depth = dfs(current.left, temp_depth, depth)
            if current.right:
                depth = dfs(current.right, temp_depth, depth)

            return depth

        return dfs(root, 0, 0) if root else 0
