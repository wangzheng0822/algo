#!/usr/bin/python
# -*- coding: UTF-8 -*-

from queue import Queue
import pygraphviz as pgv

OUTPUT_PATH = 'E:/'


class Node:
    def __init__(self, c):
        self.data = c
        self.is_ending_char = False
        # 使用有序数组，降低空间消耗，支持更多字符
        self.children = []

    def insert_child(self, c):
        self._insert_child(Node(c))

    def _insert_child(self, node):
        """
        插入一个子节点
        :param c:
        :return:
        """
        v = ord(node.data)
        idx = self._find_insert_idx(v)
        length = len(self.children)

        if idx == length:
            self.children.append(node)
        else:
            self.children.append(None)
            for i in range(length, idx, -1):
                self.children[i] = self.children[i-1]
            self.children[idx] = node

    def has_child(self, c):
        return True if self.get_child(c) is not None else False

    def get_child(self, c):
        """
        搜索子节点并返回
        :param c:
        :return:
        """
        start = 0
        end = len(self.children) - 1
        v = ord(c)

        while start <= end:
            mid = (start + end)//2
            if v == ord(self.children[mid].data):
                return self.children[mid]
            elif v < ord(self.children[mid].data):
                end = mid - 1
            else:
                start = mid + 1
        # 找不到返回None
        return None

    def _find_insert_idx(self, v):
        """
        二分查找，找到有序数组的插入位置
        :param v:
        :return:
        """
        start = 0
        end = len(self.children) - 1

        while start <= end:
            mid = (start + end)//2
            if v < ord(self.children[mid].data):
                end = mid - 1
            else:
                if mid + 1 == len(self.children) or v < ord(self.children[mid+1].data):
                    return mid + 1
                else:
                    start = mid + 1
        # v < self.children[0]
        return 0

    def __repr__(self):
        return 'node value: {}'.format(self.data) + '\n' \
               + 'children:{}'.format([n.data for n in self.children])


class Trie:
    def __init__(self):
        self.root = Node(None)

    def gen_tree(self, string_list):
        """
        创建trie树

        1. 遍历每个字符串的字符，从根节点开始，如果没有对应子节点，则创建
        2. 每一个串的末尾节点标注为红色(is_ending_char)
        :param string_list:
        :return:
        """
        for string in string_list:
            n = self.root
            for c in string:
                if n.get_child(c) is None:
                    n.insert_child(c)
                n = n.get_child(c)
            n.is_ending_char = True

    def search(self, pattern):
        """
        搜索

        1. 遍历模式串的字符，从根节点开始搜索，如果途中子节点不存在，返回False
        2. 遍历完模式串，则说明模式串存在，再检查树中最后一个节点是否为红色，是
           则返回True，否则False
        :param pattern:
        :return:
        """
        assert type(pattern) is str and len(pattern) > 0

        n = self.root
        for c in pattern:
            if n.get_child(c) is None:
                return False
            n = n.get_child(c)

        return True if n.is_ending_char is True else False

    def draw_img(self, img_name='Trie.png'):
        """
        画出trie树
        :param img_name:
        :return:
        """
        if self.root is None:
            return

        tree = pgv.AGraph('graph foo {}', strict=False, directed=False)

        # root
        nid = 0
        color = 'black'
        tree.add_node(nid, color=color, label='None')

        q = Queue()
        q.put((self.root, nid))
        while not q.empty():
            n, pid = q.get()
            for c in n.children:
                nid += 1
                q.put((c, nid))
                color = 'red' if c.is_ending_char is True else 'black'
                tree.add_node(nid, color=color, label=c.data)
                tree.add_edge(pid, nid)

        tree.graph_attr['epsilon'] = '0.01'
        tree.layout('dot')
        tree.draw(OUTPUT_PATH + img_name)
        return True


if __name__ == '__main__':
    string_list = ['abc', 'abd', 'abcc', 'accd', 'acml', 'P@trick', 'data', 'structure', 'algorithm']

    print('--- gen trie ---')
    print(string_list)
    trie = Trie()
    trie.gen_tree(string_list)
    # trie.draw_img()

    print('\n')
    print('--- search result ---')
    search_string = ['a', 'ab', 'abc', 'abcc', 'abe', 'P@trick', 'P@tric', 'Patrick']
    for ss in search_string:
        print('[pattern]: {}'.format(ss), '[result]: {}'.format(trie.search(ss)))
