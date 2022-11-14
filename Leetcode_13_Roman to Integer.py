class Solution:
    def romanToInt(self, s: str) -> int:
        last_char = ''
        sum = 0
        for _char in reversed(s):
            if _char == 'M':
                sum += 1000
            elif _char == 'D':
                sum += 500
            elif _char == 'C':
                if last_char in ['D', 'M']:
                    sum -= 100
                else:
                    sum += 100
            elif _char == 'L':
                sum += 50
            elif _char == 'X':
                if last_char in ['L', 'C']:
                    sum -= 10
                else:
                    sum += 10
            elif _char == 'V':
                sum += 5
            elif _char == 'I':
                if last_char in ['V', 'X']:
                    sum -= 1
                else:
                    sum += 1

            last_char = _char

        return sum

''' much better way

class Solution:
    def romanToInt(self, s: str) -> int:
        translations = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        number = 0
        s = s.replace("IV", "IIII").replace("IX", "VIIII")
        s = s.replace("XL", "XXXX").replace("XC", "LXXXX")
        s = s.replace("CD", "CCCC").replace("CM", "DCCCC")
        for char in s:
            number += translations[char]
        return number
'''