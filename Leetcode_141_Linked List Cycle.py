from typing import List, Optional, Tuple


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:

        if head:
            NodeList: List[Tuple[int, Optional[int]]] = []
            while head.next is not None:
                if (head.val, head.next) in NodeList:
                    return True
                else:
                    NodeList.append((head.val, head.next))
                    head = head.next

        return False
