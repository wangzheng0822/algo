"""
    Author: Wenru
"""

from typing import Optional

class DynamicArrayQueue:

    def __init__(self, capacity: int):
        self._items = []
        self._capacity = capacity
        self._head = 0
        self._tail = 0
    
    def enqueue(self, item: str) -> bool:
        if self._tail == self._capacity:
            if self._head == 0: return False
            
            self._items[0 : self._tail - self._head] = self._items[self._head : self._tail]
            self._tail -= self._head
            self._head = 0
        
        if self._tail == len(self._items):
            self._items.append(item)
        else:
            self._items[self._tail] = item
        self._tail += 1
        return True

    def dequeue(self) -> Optional[str]:
        if self._head != self._tail:
            item = self._items[self._head]
            self._head += 1
            return item
    
    def __repr__(self) -> str:
        return " ".join(item for item in self._items[self._head:self._tail])

if __name__ == "__main__":
    q = DynamicArrayQueue(10)
    for i in range(10):
        q.enqueue(str(i))
    print(q)

    for _ in range(3):
        q.dequeue()
    print(q)

    q.enqueue("7")
    q.enqueue("8")
    print(q)