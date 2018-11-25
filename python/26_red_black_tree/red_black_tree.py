#!/usr/bin/python
# -*- coding: UTF-8 -*-

from queue import Queue
import pygraphviz as pgv
import random

OUTPUT_PATH = 'E:/'


class TreeNode:
    def __init__(self, val=None, color=None):
        self.val = val
        assert color in ['r', 'b']
        self.color = 'red' if color == 'r' else 'black'

        self.left = None
        self.right = None
        self.parent = None

    def is_black(self):
        return self.color == 'black'

    def set_black(self):
        self.color = 'black'
        return

    def set_red(self):
        self.color = 'red'


class RedBlackTree:
    """
    红黑树实现
    参考资料：
    1. 《算法导论》
    第13章 红黑树
    13.3 插入 p178
    13.4 删除 p183

    2. 红黑树（二）：删除
    https://zhuanlan.zhihu.com/p/25402654
    """
    def __init__(self, val_list=None):
        self.root = None
        self.black_leaf = TreeNode(color='b')  # 共用的黑色叶子节点

        # 可用数组初始化
        if type(val_list) is list:
            for n in val_list:
                assert type(n) is int
                self.insert(n)

    def search(self, val):
        """
        搜索
        :param val:
        :return:
        """
        if self.root is None:
            return None

        n = self.root
        while n != self.black_leaf:
            if val < n.val:
                n = n.left
            elif val > n.val:
                n = n.right
            else:
                return n
        return None

    def insert(self, val):
        """
        插入
        :param val:
        :return:
        """
        assert type(val) is int

        new_node = TreeNode(val, 'r')  # 新插入的节点为红色

        # 根节点
        if self.root is None:
            self.root = new_node
        else:
            n = self.root
            while n != self.black_leaf:  # 黑色叶子节点
                p = n
                if val < n.val:
                    n = n.left
                elif val > n.val:
                    n = n.right
                else:
                    raise KeyError('val:{} already exists')  # 该值已存在，插入失败

            if val < p.val:
                p.left = new_node
            else:
                p.right = new_node
            new_node.parent = p

        new_node.left = new_node.right = self.black_leaf
        # 插入后调整
        self._insert_fixup(new_node)

    def _insert_fixup(self, node):
        """
        插入调整
        参考资料：《算法导论》 13.3 p178-179
        :param node:
        :return:
        """
        n = node
        while n is not self.root and not n.parent.is_black():
            # 父p 叔u 祖父g
            p = self.parent(n)
            u = self.bro(p)
            g = self.parent(p)

            if not u.is_black():        # case 1
                p.set_black()           # case 1
                u.set_black()           # case 1
                g.set_red()             # case 1
                n = g                   # case 1
                continue

            if p == g.left:     # p为左结点
                if n == p.right:        # case 2
                    self.rotate_l(p)    # case 2
                    n, p = p, n         # case 2
                p.set_black()           # case 3
                g.set_red()             # case 3
                self.rotate_r(g)        # case 3
            else:               # p为右节点
                if n == p.left:         # case 2
                    self.rotate_r(p)    # case 2
                    n, p = p, n         # case 2
                p.set_black()           # case 3
                g.set_red()             # case 3
                self.rotate_l(g)        # case 3

        # 根节点强制置黑，有两种情况根节点是红色：
        # 1. 新插入时是红色
        # 2. 经过case 1调整过后变红色
        self.root.color = 'black'

    def delete(self, val):
        """
        删除
        :param val:
        :return:
        """
        assert type(val) is int

        n = self.search(val)
        if n is None:
            print('can not find any nodes with value: {}'.format(val))
            return

        self._delete_node(n)

    def _delete_node(self, node):
        """
        删除节点内部实现
        参考资料：《算法导论》 13.4 p183-184
        实现方式有微调，当n有2个子节点时，将s拷贝至n，转为删除s(s最多有一个子节点)
        :param node:
        :return:
        """
        n = node

        # n的子节点个数等于2
        if self.children_count(n) == 2:
            # 寻找n的后继s
            s = n.right
            while s.left != self.black_leaf:
                s = s.left
            n.val = s.val
            # 将删除n转化为删除s
            n = s

        # n的子节点个数小于2
        if n.left == self.black_leaf:
            c = n.right
        else:
            c = n.left
        self._transplant(n, c)

        # 删除的节点是黑色，需要调整
        if n.is_black():
            self._delete_fixup(c)
        return

    def _delete_fixup(self, node):
        """
        删除调整
        参考资料：《算法导论》 13.4 p185-187
        :param node:
        :return:
        """
        n = node
        while n != self.root and n.is_black():
            p = self.parent(n)
            b = self.bro(n)

            # 左右节点对称
            if p.left == n:
                if not b.is_black():
                    b.set_black()                   # case 1
                    p.set_red()                     # case 1
                    self.rotate_l(p)                # case 1
                    # new bro after rotate
                    b = self.bro(n)                 # case 1

                if b.left.is_black() and b.right.is_black():
                    b.set_red()                     # case 2
                    n = p                           # case 2
                else:
                    if b.right.is_black():
                        b.left.set_black()          # case 3
                        b.set_red()                 # case 3
                        self.rotate_r(b)            # case 3
                        # new bro after rotate
                        b = self.bro(n)             # case 3

                    # 注意，因为p可能是红或黑，所以不能直接赋值颜色，只能copy
                    b.color = p.color               # case 4
                    p.set_black()                   # case 4
                    b.right.set_black()             # case 4
                    self.rotate_l(p)                # case 4
                    # trick, 调整结束跳出while
                    n = self.root                   # case 4
            else:
                if not b.is_black():
                    b.set_black()                   # case 1
                    p.set_red()                     # case 1
                    self.rotate_r(p)                # case 1
                    # new bro after rotate
                    b = self.bro(n)                 # case 1

                if b.left.is_black() and b.right.is_black():
                    b.set_red()                     # case 2
                    n = p                           # case 2
                else:
                    if b.left.is_black():
                        b.right.set_black()         # case 3
                        b.set_red()                 # case 3
                        self.rotate_l(b)            # case 3
                        # new bro after rotate
                        b = self.bro(n)             # case 3

                    # 注意，因为p可能是红或黑，所以不能直接赋值颜色，只能copy
                    b.color = p.color               # case 4
                    p.set_black()                   # case 4
                    b.left.set_black()              # case 4
                    self.rotate_r(p)                # case 4
                    # trick, 调整结束跳出while
                    n = self.root                   # case 4

        # 将n设为黑色，从上面while循环跳出，情况有两种
        # 1. n是根节点，直接无视附加的黑色
        # 2. n是红色的节点，则染黑
        n.set_black()

    def _transplant(self, n1, n2):
        """
        节点移植， n2 -> n1
        :param n1: 原节点
        :param n2: 移植节点
        :return:
        """
        if n1 == self.root:
            if n2 != self.black_leaf:
                self.root = n2
                n2.parent = None
            else:
                self.root = None    # 只有删除根节点时会进来
        else:
            p = self.parent(n1)
            if p.left == n1:
                p.left = n2
            else:
                p.right = n2

            n2.parent = p

    def rotate_l(self, node):
        """
        左旋
        :param node:
        :return:
        """
        if node is None:
            return

        if node.right is self.black_leaf:
            return
            # raise Exception('try rotate left , but the node "{}" has no right child'.format(node.val))

        p = self.parent(node)
        x = node
        y = node.right

        # node为根节点时，p为None，旋转后要更新根节点指向
        if p is not None:
            if x == p.left:
                p.left = y
            else:
                p.right = y
        else:
            self.root = y

        x.parent, y.parent = y, p

        if y.left != self.black_leaf:
            y.left.parent = x

        x.right, y.left = y.left, x

    def rotate_r(self, node):
        """
        右旋
        :param node:
        :return:
        """
        if node is None:
            return

        if node.left is self.black_leaf:
            return
            # raise Exception('try rotate right , but the node "{}" has no left child'.format(node.val))

        p = self.parent(node)
        x = node
        y = node.left

        # 同左旋
        if p is not None:
            if x == p.left:
                p.left = y
            else:
                p.right = y
        else:
            self.root = y

        x.parent, y.parent = y, p

        if y.right is not None:
            y.right.parent = x

        x.left, y.right = y.right, x

    @staticmethod
    def bro(node):
        """
        获取兄弟节点
        :param node:
        :return:
        """
        if node is None or node.parent is None:
            return None
        else:
            p = node.parent
            if node == p.left:
                return p.right
            else:
                return p.left

    @staticmethod
    def parent(node):
        """
        获取父节点
        :param node:
        :return:
        """
        if node is None:
            return None
        else:
            return node.parent

    def children_count(self, node):
        """
        获取子节点个数
        :param node:
        :return:
        """
        return 2 - [node.left, node.right].count(self.black_leaf)

    def draw_img(self, img_name='Red_Black_Tree.png'):
        """
        画图
        用pygraphviz画出节点和箭头
        箭头的红色和黑色分别代表左和右
        :param img_name:
        :return:
        """
        if self.root is None:
            return

        tree = pgv.AGraph(directed=True, strict=True)

        q = Queue()
        q.put(self.root)

        while not q.empty():
            n = q.get()
            if n != self.black_leaf:  # 黑色叶子的连线由各个节点自己画
                tree.add_node(n.val, color=n.color)
                #  画父节点箭头
                # if n.parent is not None:
                #     tree.add_edge(n.val, n.parent.val)

                for c in [n.left, n.right]:
                    q.put(c)
                    color = 'red' if c == n.left else 'black'
                    if c != self.black_leaf:
                        tree.add_edge(n.val, c.val, color=color)
                    else:
                        tree.add_edge(n.val, 'None', color=color)

        tree.graph_attr['epsilon'] = '0.01'
        tree.layout('dot')
        tree.draw(OUTPUT_PATH + img_name)
        return True


if __name__ == '__main__':
    rbt = RedBlackTree()

    # insert
    nums = list(range(1, 25))
    # random.shuffle(nums)
    for num in nums:
        rbt.insert(num)

    # search
    search_num = 23
    n = rbt.search(search_num)
    if n is not None:
        print(n)
    else:
        print('node {} not found'.format(search_num))

    # delete
    rbt.delete(4)

    # draw image
    rbt.draw_img('rbt.png')
