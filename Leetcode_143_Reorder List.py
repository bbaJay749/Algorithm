from collections import deque
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:

        # Put all nodes in a deque
        ListNodes = deque()
        current_head = head
        while current_head:
            ListNodes.append(current_head)
            current_head = current_head.next

        # reorder singly-linked list using deque's pop and popleft
        current_head = head = ListNodes.popleft()
        flag = 'R'
        while len(ListNodes):
            if flag == 'R':
                current_head.next = ListNodes.pop()
                current_head = current_head.next
                flag = 'L'
            elif flag == 'L':
                current_head.next = ListNodes.popleft()
                current_head = current_head.next
                flag = 'R'
        current_head.next = None
