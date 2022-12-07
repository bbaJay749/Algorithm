from collections import deque


class Solution:
    def isValid(self, s: str) -> bool:
        bracketChecker = deque()

        for bracket in s:
            if bracket in ['(', '{', '[']:
                bracketChecker.append(bracket)
            elif bracket in [')', '}', ']']:
                if len(bracketChecker) == 0:
                    return False
                elif bracket == ')' and bracketChecker[-1] == '(':
                    bracketChecker.pop()
                elif bracket == '}' and bracketChecker[-1] == '{':
                    bracketChecker.pop()
                elif bracket == ']' and bracketChecker[-1] == '[':
                    bracketChecker.pop()
                else:
                    return False
                
        if len(bracketChecker) > 0:
            return False
        else:
            return True
        
        
''' much better way

class Solution:
    def isValid(self, s: str) -> bool:
        map = {')':'(', '}':'{', ']':'['}
        st = []
        for c in s:
            if len(st)==0 or not c in map.keys():
                st.append(c)
            elif map.get(c)==st[-1]:
                st.pop()
            else:
                st.append(c)
        return len(st)==0
'''