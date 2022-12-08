from typing import List


class Solution:

    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ''
        charSet = set()
        minLen = len(min(strs, key=len))

        for idx in range(0, minLen):
            for str in strs:
                charSet.add(str[idx])
            if len(charSet) == 1:
                prefix += charSet.pop()
                charSet = set()
            else:
                return prefix

        return prefix


''' much better way

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:

        if not strs:
            return ""
        shortest = min(strs,key=len)
        for i, ch in enumerate(shortest):
            for other in strs:
                if other[i] != ch:
                    return shortest[:i]
        return shortest
'''