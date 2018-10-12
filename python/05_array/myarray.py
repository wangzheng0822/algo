from typing import Optional
#
# 1) Insertion, deletion and random access of array
# 2) Assumes int for element type
#
# Author: Wenru
#
class MyArray:
    """A simple wrapper around List.
    You cannot have -1 in the array.
    """
    def __init__(self, capacity: int):
        self._data = []
        self._count = 0
        self._capacity = capacity
    
    def __getitem__(self, position: int) -> int:
        """Support for subscript.
        Perhaps better than the find() method below.
        """
        return self._data[position]

    def find(self, index: int) -> Optional[int]:
        if index >= self._count or index <= -self._count: return None
        return self._data[index]

    def delete(self, index: int) -> bool:
        if index >= self._count or index <= -self._count: return False
        self._data[index:-1] = self._data[index+1:]
        self._count -= 1
        return True

    def insert(self, index: int, value: int) -> bool:
        if index >= self._count or index <= -self._count: return False
        if self._capacity == self._count: return False
        self._data.insert(index, value)
        self._count += 1
        return True

    def insert_to_tail(self, value: int) -> bool:
        if self._count == self._capacity: return False
        if self._count == len(self._data):
            self._data.append(value) 
        else:
            self._data[self._count] = value
        self._count += 1
        return True
    
    def __repr__(self) -> str:
        return " ".join(str(num) for num in self._data[:self._count])

    def print_all(self):
        for num in self._data[:self._count]:
            print(f"{num}", end=" ")
        print("\n", flush=True)

if __name__ == "__main__":
    a = MyArray(6)
    for i in range(6):
        a.insert_to_tail(i)
    
    a.delete(2)
    print(a)
    a.insert_to_tail(7)
    print(a)