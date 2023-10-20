from typing import List, Optional
from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result: List[List[int]] = []
        if root is None:
            return result

        same_level_node_queue = deque()
        next_level_node_queue = deque()
        same_level_node_queue.append(root)

        same_level_nodes: List[int] = []
        while same_level_node_queue:
            node: TreeNode = same_level_node_queue.popleft()
            same_level_nodes.append(node.val)

            if node.left:
                next_level_node_queue.append(node.left)
            if node.right:
                next_level_node_queue.append(node.right)

            if len(same_level_node_queue) == 0:
                result.append(same_level_nodes)

                if len(next_level_node_queue) == 0:
                    return result

                same_level_nodes = []
                same_level_node_queue.extend(next_level_node_queue)
                next_level_node_queue.clear()
