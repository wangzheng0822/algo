"""
    Aho-Corasick Algorithm

    Author: Wenru Dong
"""

from collections import deque
from typing import List

class ACNode:
    def __init__(self, data: str):
        self._data = data
        self._children = [None] * 26
        self._is_ending_char = False
        self._length = -1
        self._suffix = None
    

class ACAutomata:
    def __init__(self):
        self._root = ACNode("/")

    def _build_suffix_link(self) -> None:
        q = deque()
        q.append(self._root)
        while q:
            node = q.popleft()
            for child in node._children:
                if child:
                    if node == self._root:
                        child._suffix = self._root
                    else:
                        suffix = node._suffix
                        while suffix:
                            suffix_child = suffix._children[ord(child._data) - ord("a")]
                            if suffix_child:
                                child._suffix = suffix_child
                                break
                            suffix = suffix._suffix
                        if not suffix:
                            child._suffix = self._root
                    q.append(child)

    def _insert(self, text: str) -> None:
        node = self._root
        for index, char in map(lambda x: (ord(x) - ord("a"), x), text):
            if not node._children[index]:
                node._children[index] = ACNode(char)
            node = node._children[index]
        node._is_ending_char = True
        node._length = len(text)

    def insert(self, patterns: List[str]) -> None:
        for pattern in patterns:
            self._insert(pattern)
        self._build_suffix_link()

    def match(self, text: str) -> None:
        node = self._root
        for i, char in enumerate(text):
            index = ord(char) - ord("a")
            while not node._children[index] and node != self._root:
                node = node._suffix
            node = node._children[index]
            if not node:
                node = self._root
            tmp = node
            while tmp != self._root:
                if tmp._is_ending_char:
                    print(f"匹配起始下标{i - tmp._length + 1}，长度{tmp._length}")
                tmp = tmp._suffix


if __name__ == "__main__":

    patterns = ["at", "art", "oars", "soar"]
    ac = ACAutomata()
    ac.insert(patterns)
    
    ac.match("soarsoars")
