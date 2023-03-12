class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        left = 0
        result = 0

        for idx, _char in enumerate(s):
            if _char in seen:
                # Char is out of current window.
                if seen[_char] < left:
                    result = max(result, idx - left + 1)
                # Char is in current window. move window.
                else:
                    left = seen[_char] + 1

            # Increase window and check max value.
            else:
                result = max(result, idx - left + 1)

            seen[_char] = idx

        return result
