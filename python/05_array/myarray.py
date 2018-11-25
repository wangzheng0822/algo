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

        if index >= self._count or index <= -self._count:
            return None
        return self._data[index]

    def delete(self, index: int) -> bool:

        if index >= self._count or index <= -self._count:
            return False

        self._data[index:-1] = self._data[index + 1:]
        self._count -= 1
        # 真正将数据删除并覆盖原来的数据 ，这个需要增加
        self._data = self._data[0:self._count]
        print('delete function', self._data)
        return True

    def insert(self, index: int, value: int) -> bool:

        # if index >= self._count or index <= -self._count: return False
        if self._capacity == self._count:
            return False
        # 如果还有空间，那么插入位置大于当前的元素个数，可以插入最后的位置
        if index >= self._count:
            self._data.append(value)
        # 同上，如果位置小于0 可以插入第０个位置.
        if index < 0:
            print(index)
            self._data.insert(0, value)

        self._count += 1
        return True

    def insert_to_tail(self, value: int) -> bool:

        if self._count == self._capacity:
            return False
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


def test_myarray():
    array_a = MyArray(6)
    for num in range(6):
        array_a.insert_to_tail(num)
    assert array_a.find(0) == 0
    assert array_a[0] == 0
    array_a.delete(0)
    assert array_a[0] == 1


if __name__ == "__main__":
    a = MyArray(6)
    for i in range(6):
        a.insert_to_tail(i)
    a.delete(2)
    print(a)
    a.insert_to_tail(7)
    print(a)
    print('origin', a)
    a.delete(4)
    print('delete ', a)

    a.insert(100, 10000)
    print(a)
