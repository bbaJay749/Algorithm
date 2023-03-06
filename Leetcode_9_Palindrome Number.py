from collections import deque


class Solution:
    def isPalindrome(self, x: int) -> bool:
        x_string = deque(str(x))

        for _ in range(len(x_string)//2):
            front = x_string.pop()
            rear = x_string.popleft()
            if front != rear:
                return False
        return True
