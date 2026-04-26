from typing import Optional, Any

class ArrayQueue:
    
    def __init__(self, capacity: int):
        if capacity <= 0:
            raise ValueError("capacity must be positive")
        self._items = [None] * capacity  # 预分配固定数组
        self._capacity = capacity
        self._head = 0
        self._tail = 0

    def enqueue(self, item: Any) -> bool:
        if self._tail == self._capacity:
            if self._head == 0:
                return False  # 真的满了
            # 搬移：把 [head, tail) 的元素平移到头部
            for i in range(self._tail - self._head):
                self._items[i] = self._items[i + self._head]
            self._tail -= self._head
            self._head = 0
        
        self._items[self._tail] = item  # 直接赋值，O(1)
        self._tail += 1
        return True
    
    def dequeue(self) -> Optional[Any]:
        if self._head == self._tail:
            return None
        item = self._items[self._head]
        self._items[self._head] = None  # 帮助 GC
        self._head += 1
        return item
    
    def __repr__(self) -> str:
        return " ".join(str(item) for item in self._items[self._head:self._tail])
