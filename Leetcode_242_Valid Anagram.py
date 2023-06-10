from typing import Dict


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        value_count_s: Dict[str, int] = dict()
        value_count_t: Dict[str, int] = dict()

        for character in s:
            if character not in value_count_s.keys():
                value_count_s[character] = 1
            else:
                value_count_s[character] += 1

        for character in t:
            if character not in value_count_t.keys():
                value_count_t[character] = 1
            else:
                value_count_t[character] += 1

        if value_count_s.keys() != value_count_t.keys():
            return False

        for key in value_count_s.keys():
            if value_count_s[key] != value_count_t[key]:
                return False

        return True
