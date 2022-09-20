class DbListNode(object):
    def __init__(self, x, y):
        self.key = x
        self.val = y
        self.next = None
        self.prev = None


class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.hkeys = {}
        # self.top和self.tail作为哨兵节点, 避免越界
        self.top = DbListNode(None, -1)   # top节点的下一个节点是真正的headnode(第一个节点, 头结点)
        self.tail = DbListNode(None, -1)  # tail一开始充当的是headnode
        self.top.next = self.tail
        self.tail.prev = self.top

    def get(self, key: int) -> int:
        cur = self.hkeys.get(key,None)
        if cur:
            # 跳出原位置
            delete_cur_node(cur)
            # 最近用过的置于链表首部
            replace_headnode(self, cur)
            return self.hkeys[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        cur = self.hkeys.get(key,None)
        if cur:
            cur.val = value
            # 跳出原位置
            delete_cur_node(cur)
            replace_headnode(self, cur)
        else:
            # 增加新结点至首部
            cur = DbListNode(key, value)
            self.hkeys[key] = cur   # {1 : node}
            replace_headnode(self, cur)
            if len(self.hkeys.keys()) > self.cap:
                self.hkeys.pop(self.tail.prev.key)
                # 去掉原尾结点
                self.tail.prev.prev.next = self.tail
                self.tail.prev = self.tail.prev.prev

    def __repr__(self):
        vals = []
        p = self.top.next
        while p.next:
            vals.append(str(p.val))
            p = p.next
        return '->'.join(vals)


def delete_cur_node(cur):
    '''
    删除当前节点
    '''
    cur.next.prev = cur.prev
    cur.prev.next = cur.next


def replace_headnode(self, cur):
    """
    将第一个head node替换为当前节点

    cur: 当前节点
    """
    top_node = self.top.next   # 一开始的是tail
    self.top.next = cur        # 变成cur
    cur.prev = self.top        #  
    cur.next = top_node        # top cur tail
    top_node.prev = cur        # 最开始的headnode的前一个变成了cur

if __name__ == '__main__':
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    print(cache)
    cache.get(1)  # 返回  1
    cache.put(3, 3)  # 该操作会使得密钥 2 作废
    print(cache)
    cache.get(2)  # 返回 -1 (未找到)
    cache.put(4, 4)  # 该操作会使得密钥 1 作废
    print(cache)
    cache.get(1)  # 返回 -1 (未找到)
    cache.get(3)  # 返回  3
    print(cache)
    cache.get(4)  # 返回  4
    print(cache)