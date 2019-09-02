#!/usr/bin/python
# -*- coding: UTF-8 -*-

from trie_ import Node, Trie
from queue import Queue


class ACNode(Node):
    def __init__(self, c: str):
        super(ACNode, self).__init__(c)
        self.fail = None
        self.length = 0

    def insert_child(self, c: str):
        self._insert_child(ACNode(c))


class ACTrie(Trie):
    def __init__(self):
        self.root = ACNode(None)


def ac_automata(main: str, ac_trie: ACTrie) -> list:
    root = ac_trie.root
    build_failure_pointer(ac_trie)

    ret = []
    p = root
    for i, c in enumerate(main):
        while p != root and not p.has_child(c):
            p = p.fail

        if p.has_child(c):  # a char matched, try to find all potential pattern matched
            q = p.get_child(c)
            while q != root:
                if q.is_ending_char:
                    ret.append((i-q.length+1, i))
                    # ret.append(main[i-q.length+1:i+1])
                q = q.fail
            p = p.get_child(c)

    return ret


def build_failure_pointer(ac_trie: ACTrie) -> None:
    root = ac_trie.root

    # queue: [(node, node.length) ....]
    node_queue = Queue()
    node_queue.put((root, root.length))

    root.fail = None
    while not node_queue.empty():
        p, length = node_queue.get()
        for pc in p.children:
            pc.length = length + 1
            if p == root:
                pc.fail = root
            else:
                q = p.fail
                # same as kmp
                while q != root and not q.has_child(pc.data):
                    q = q.fail

                # cases now:
                # 1. q == root
                # 2. q != root and q.has_child(pc.data)
                if q.has_child(pc.data):
                    pc.fail = q.get_child(pc.data)
                else:
                    pc.fail = root
            node_queue.put((pc, pc.length))


if __name__ == '__main__':
    ac_trie = ACTrie()
    ac_trie.gen_tree(['fuck', 'shit', 'TMD', '傻叉'])

    print('--- ac automata ---')
    m_str = 'fuck you, what is that shit, TMD你就是个傻叉傻叉傻叉叉'
    print('original str  : {}'.format(m_str))

    filter_range_list = ac_automata(m_str, ac_trie)
    str_filtered = m_str
    for start, end in filter_range_list:
        str_filtered = str_filtered.replace(str_filtered[start:end+1], '*'*(end+1-start))

    print('after filtered: {}'.format(str_filtered))
