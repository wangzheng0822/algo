# 1.单链表的插入、删除、查找操作；
# 2.链表中存储的数据类型是Int
#
# Author:Lee

class Node():
    '''链表结构的Node节点'''

    def __init__(self, data, next=None):
        '''Node节点的初始化方法.
        参数:
            data:存储的数据
            next:下一个Node节点的引用地址
        '''
        self.__data = data
        self.__next = next

    @property
    def data(self):
        '''Node节点存储数据的获取.
        返回:
            当前Node节点存储的数据
        '''
        return self.__data

    @data.setter
    def data(self, data):
        '''Node节点存储数据的设置方法.
        参数:
            data:新的存储数据
        '''
        self.__data = data

    @property
    def next(self):
        '''获取Node节点的next指针值.
        返回:
            next指针数据
        '''
        return self.__next

    @next.setter
    def next(self, next):
        '''Node节点next指针的修改方法.
        参数:
            next:新的下一个Node节点的引用
        '''
        self.__next = next


class SinglyLinkedList():
    '''单向链表'''

    def __init__(self):
        '''单向列表的初始化方法.'''
        self.__head = None

    def find_by_value(self, value):
        '''按照数据值在单向列表中查找.
        参数:
            value:查找的数据
        返回:
            Node
        '''
        node = self.__head
        if node != None and node.data != value:
            node = node.next
        else:
            return node

    def find_by_index(self, index):
        '''按照索引值在列表中查找.
        参数:
            index:索引值
        返回:
            Node
        '''
        node = self.__head
        pos = 0
        while node != None and pos != index:
            node = node.next
            pos += 1
        return node

    def insert_to_head(self, value):
        '''在链表的头部插入一个存储value数值的Node节点.
        参数:
            value:将要存储的数据
        '''
        node = Node(value)
        node.next = self.__head
        self.__head = node

    def insert_after(self, node, value):
        '''在链表的某个指定Node节点之后插入一个存储value数据的Node节点.
        参数:
            node:指定的一个Node节点
            value:将要存储在新Node节点中的数据
        '''
        if node == None:  # 如果指定在一个空节点之后插入数据节点，则什么都不做
            return

        new_node = Node(value)
        new_node.next = node.next
        node.next = new_node

    def insert_before(self, node, value):
        '''在链表的某个指定Node节点之前插入一个存储value数据的Node节点.
        参数:
            node:指定的一个Node节点
            value:将要存储在新的Node节点中的数据
        '''
        if node == None or self.__head == None:  # 如果指定在一个空节点之前或者空链表之前插入数据节点，则什么都不做
            return

        if node == self.__head:  # 如果是在链表头之前插入数据节点，则直接插入
            self.insert_to_head(value)
            return

        new_node = Node(value)
        pro = self.__head
        not_found = False  # 如果在整个链表中都没有找到指定插入的Node节点，则该标记量设置为True
        while pro.next != node:  # 寻找指定Node之前的一个Node
            if pro.next == None:  # 如果已经到了链表的最后一个节点，则表明该链表中没有找到指定插入的Node节点
                not_found = True
                break
            else:
                pro = pro.next
        if not_found == False:
            pro.next = new_node
            new_node.next = node

    def delete_by_node(self, node):
        '''在链表中删除指定Node的节点.
        参数:
            node:指定的Node节点
        '''
        if self.__head == None:  # 如果链表是空的，则什么都不做
            return

        if node == self.__head:  # 如果指定删除的Node节点是链表的头节点
            self.__head = node.next
            return

        pro = self.__head
        not_found = False  # 如果在整个链表中都没有找到指定删除的Node节点，则该标记量设置为True
        while pro.next != node:
            if pro.next == None:  # 如果已经到链表的最后一个节点，则表明该链表中没有找到指定删除的Node节点
                not_found == True
                break
            else:
                pro = pro.next
        if not_found == False:
            pro.next = node.next

    def delete_by_value(self, value):
        '''在链表中删除指定存储数据的Node节点.
        参数:
            value:指定的存储数据
        '''
        if self.__head == None:  # 如果链表是空的，则什么都不做
            return

        if self.__head.data == value:  # 如果链表的头Node节点就是指定删除的Node节点
            self.__head = self.__head.next

        pro = self.__head
        node = self.__head.next
        not_found = False
        while node.data != value:
            if node.next == None:  # 如果已经到链表的最后一个节点，则表明该链表中没有找到执行Value值的Node节点
                not_found == True
                break
            else:
                pro = node
                node = node.next
        if not_found == False:
            pro.next = node.next

    def delete_last_N_node(self, n):
        '''删除链表中倒数第N个节点.
        主体思路：
            设置快、慢两个指针，快指针先行，慢指针不动；当快指针跨了N步以后，快、慢指针同时往链表尾部移动，
            当快指针到达链表尾部的时候，慢指针所指向的就是链表的倒数第N个节点
        参数:
            n:需要删除的倒数第N个序数
        '''
        fast = self.__head
        slow = self.__head
        step = 0

        while step <= n:
            fast = fast.next
            step += 1

        while fast.next != None:
            tmp = slow
            fast = fast.next
            slow = slow.next

        tmp.next = slow.next

    def find_mid_node(self):
        '''查找链表中的中间节点.
        主体思想:
            设置快、慢两种指针，快指针每次跨两步，慢指针每次跨一步，则当快指针到达链表尾部的时候，慢指针指向链表的中间节点
        返回:
            node:链表的中间节点
        '''
        fast = self.__head
        slow = self.__head

        while fast.next != None:
            fast = fast.next.next
            slow = slow.next

        return slow

    def create_node(self, value):
        '''创建一个存储value值的Node节点.
        参数:
            value:将要存储在Node节点中的数据
        返回:
            一个新的Node节点
        '''
        return Node(value)

    def print_all(self):
        '''打印当前链表所有节点数据.'''
        pos = self.__head
        if pos == None:
            print('当前链表还没有数据')
            return
        while pos.next != None:
            print(str(pos.data) + ' --> ', end='')
            pos = pos.next
        print(str(pos.data))

    def reversed_self(self):
        '''翻转链表自身.'''
        if self.__head == None or self.__head.next == None:  # 如果链表为空，或者链表只有一个节点
            return

        pre = self.__head
        node = self.__head.next
        while node != None:
            pre, node = self.__reversed_with_two_node(pre, node)

        self.__head.next = None
        self.__head = pre

    def __reversed_with_two_node(self, pre, node):
        '''翻转相邻两个节点.
        参数:
            pre:前一个节点
            node:当前节点
        返回:
            (pre,node):下一个相邻节点的元组
        '''
        tmp = node.next
        node.next = pre
        pre = node  # 这样写有点啰嗦，但是能让人更能看明白
        node = tmp
        return (pre, node)

    def has_ring(self):
        '''检查链表中是否有环.
        主体思想：
            设置快、慢两种指针，快指针每次跨两步，慢指针每次跨一步，如果快指针没有与慢指针相遇而是顺利到达链表尾部
            说明没有环；否则，存在环
        返回:
            True:有环
            False:没有环
        '''
        fast = self.__head
        slow = self.__head

        while fast.next != None and fast != None:
            fast = fast.next
            slow = slow.next
            if fast == slow:
                return True

        return False
