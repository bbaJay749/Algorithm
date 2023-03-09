from collections import deque


# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node

        q = deque([node])
        graph_dict = {1: Node(node.val)}
        while q:
            n = q.popleft()

            if not n.neighbors:
                continue

            for neighbor in n.neighbors:
                # To check if current node's neighbor has already checked.
                if neighbor.val not in graph_dict.keys():
                    q.append(neighbor)
                    graph_dict[neighbor.val] = Node(neighbor.val)
                graph_dict[n.val].neighbors.append(graph_dict[neighbor.val])

        return graph_dict[node.val]