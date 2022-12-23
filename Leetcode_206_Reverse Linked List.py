from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    """
    Reverse Linked List, singly linked list,
    """

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        current_node = head
        temp = None

        while current_node is not None:
            next_node, current_node.next = current_node.next, temp
            current_node, temp = next_node, current_node

        return temp