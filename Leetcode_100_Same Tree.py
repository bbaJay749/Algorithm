from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        elif (not p and q) or (p and not q):
            return False

        def dfs(p: Optional[TreeNode], q: Optional[TreeNode]):
            if p.val == q.val:
                # check left
                if p.left and q.left:
                    if dfs(p.left, q.left) is False:
                        return False
                elif p.left is None and q.left is None:
                    pass
                else:
                    return False
                # check right
                if p.right and q.right:
                    if dfs(p.right, q.right) is False:
                        return False
                elif p.right is None and q.right is None:
                    pass
                else:
                    return False
            else:
                return False

            # finish fine
            return True

        return dfs(p, q)
