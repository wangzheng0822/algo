# 跳表（Skip List）

支持快速地：

* 插入
* 删除
* 查找

某些情况下，跳表甚至可以替代红黑树（Red-Black tree）。Redis 当中的有序集合（Sorted Set）是用跳表实现的。

## 跳表的结构

跳表是对链表的改进。对于单链表来说，即使内容是有序的，查找具体某个元素的时间复杂度也要达到 $O(n)$。对于二分查找来说，由于链表不支持随机访问，根据 `first` 和 `last` 确定 `cut` 时，必须沿着链表依次迭代 `std::distance(first, last) / 2` 步；特别地，计算 `std::(first, last)` 本身，就必须沿着链表迭代才行。此时，二分查找的效率甚至退化到了 $O(n \log n)$，甚至还不如顺序遍历。

![单链表查找示例](https://static001.geekbang.org/resource/image/e1/6d/e18303fcedc068e5a168de04df956f6d.jpg)

跳表的核心思想是用空间换时间，构建足够多级数的索引，来缩短查找具体值的时间开销。

![具有二级索引的跳表示例](https://static001.geekbang.org/resource/image/49/65/492206afe5e2fef9f683c7cff83afa65.jpg)

例如对于一个具有 64 个有序元素的五级跳表，查找起来的过程大约如下图所示。

![五级跳表示例](https://static001.geekbang.org/resource/image/46/a9/46d283cd82c987153b3fe0c76dfba8a9.jpg)
