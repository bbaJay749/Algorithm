import re


class WordDictionary:

    def __init__(self):
        self.word_dict = set()

    def addWord(self, word: str) -> None:
        if word is not None and word != '':
            self.word_dict.add(word)

    def genPattern(self, word: str) -> str:
        result = '^'

        temp_dot = 0
        for ch in word:
            if ch == '.':
                temp_dot += 1
            elif temp_dot > 0:
                result += '.{' + str(temp_dot) + '}' + ch
                temp_dot = 0
            else:
                result += ch
        if temp_dot > 0:
            result += '.{' + str(temp_dot) + '}'

        result += '$'
        return re.compile(result)

    def search(self, word: str) -> bool:
        if '.' not in word:
            return True if word in self.word_dict else False
        else:
            pattern = self.genPattern(word)
            for word_from_dict in self.word_dict:
                if pattern.search(word_from_dict):
                    return True
            return False


''' Better way using trie

class WordDictionary:

    def __init__(self):
        self.trie = dict()

    def addWord(self, word: str) -> None:
        node = self.trie
        for ch in word + '🔚':
            if ch not in node:
                node[ch] = dict()

            node = node[ch]

    def search(self, word: str) -> bool:
        nodes = [self.trie]
        for ch in word + '🔚':
            newNodes = []
            for node in nodes:
                if ch == '.':
                    newNodes += [v for v in node.values()]
                elif ch in node:
                    newNodes.append(node[ch])

            if not newNodes:
                return False

            nodes = newNodes

        return True
'''
