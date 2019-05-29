"""
    Author: Wenru Dong
"""

from typing import Optional

class Bitmap:
    def __init__(self, num_bits: int):
        self._num_bits = num_bits
        self._bytes = bytearray(num_bits // 8 + 1)
    
    def setbit(self, k: int) -> None:
        if k > self._num_bits or k < 1: return
        self._bytes[k // 8] |= (1 << k % 8)
    
    def getbit(self, k: int) -> Optional[bool]:
        if k > self._num_bits or k < 1: return
        return self._bytes[k // 8] & (1 << k % 8) != 0


if __name__ == "__main__":
    bitmap = Bitmap(10)
    bitmap.setbit(1)
    bitmap.setbit(3)
    bitmap.setbit(6)
    bitmap.setbit(7)
    bitmap.setbit(8)

    for i in range(1, 11):
        print(bitmap.getbit(i))