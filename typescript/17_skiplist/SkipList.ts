/**
 * 跳跃表是Redis使用的底层算法
 * 在增删改查都有近似O（log n）的时间复杂度
 * 哈希表虽然在不产生冲突的情况下是O（1）的时间复杂度
 * 但是随着冲突的增多，所需要的扩容操作还是比较耗时的，综合起来不一定快于跳表
 * 这两种结构可以互相补充
 * 下面摘抄一段来自知乎的话 (https://juejin.im/post/57fa935b0e3dd90057c50fbc）
 * 比较跳表和哈希表，平衡树之间的区别
 * skiplist和各种平衡树（如AVL、红黑树等）的元素是有序排列的，而哈希表不是有序的。因此，在哈希表上只能做单个key的查找，不适宜做范围查找。所谓范围查找，指的是查找那些大小在指定的两个值之间的所有节点。
 * 在做范围查找的时候，平衡树比skiplist操作要复杂。在平衡树上，我们找到指定范围的小值之后，还需要以中序遍历的顺序继续寻找其它不超过大值的节点。
 * 如果不对平衡树进行一定的改造，这里的中序遍历并不容易实现。而在skiplist上进行范围查找就非常简单，只需要在找到小值之后，对第1层链表进行若干步的遍历就可以实现。
 * 平衡树的插入和删除操作可能引发子树的调整，逻辑复杂，而skiplist的插入和删除只需要修改相邻节点的指针，操作简单又快速。
 * 从内存占用上来说，skiplist比平衡树更灵活一些。一般来说，平衡树每个节点包含2个指针（分别指向左右子树），而skiplist每个节点包含的指针数目平均为1/(1-p)，具体取决于参数p的大小。
 * 如果像Redis里的实现一样，取p=1/4，那么平均每个节点包含1.33个指针，比平衡树更有优势。
 * 查找单个key，skiplist和平衡树的时间复杂度都为O(log n)，大体相当；而哈希表在保持较低的哈希值冲突概率的前提下，查找时间复杂度接近O(1)，性能更高一些。所以我们平常使用的各种Map或dictionary结构，大都是基于哈希表实现的。
 * 从算法实现难度上来比较，skiplist比平衡树要简单。
 */
export class SkipList<T> {
  // head和tail始终指向最顶层的首位节点，通过链表能访问任何位置
  private head: SkipListNode<T>
  private tail: SkipListNode<T>

  // 索引的层数，0表示最底层
  private levelCount = 0

  // 元素的个数
  private size = 0

  // private readonly MAX_LEVEL = 16


  constructor() {
    this.head = new SkipListNode<T>(SkipListNode.negInf, null)
    this.tail = new SkipListNode<T>(SkipListNode.posInf, null)
  }

  public insert(key: number, value: T): void {
    let p: SkipListNode<T>
    let q: SkipListNode<T>

    let i: number = 0

    // 先查找位置
    p = this.findNode(key)

    // 如果跳跃表中的值已经存在了，直接赋值即可
    if (p.key === key) {
      p.value = value
      return
    }

    // 没有该值，则进行插入操作,应该是插在p节点的右边. p -> q -> ?
    q = new SkipListNode(key, value)
    q.left = p
    q.right = p.right
    if (p.right) {
      p.right.left = q
    }
    p.right = q

    // 再使用随机数决定是否要向更高层攀升
    while (Math.random() < 0.5) {
      // 如果新元素的级别已经达到跳跃表的最大高度，则新建空白层
      if (i >= this.levelCount) {
        this.addEmptyLevel()
      }

      // 从p向左扫描含有高层节点的节点, 方便节点在每一层插入
      while (!p.up) {
        p = p.left!
      }
      p = p.up

      // 新值对应的索引，这里不需要存value了，因为只需要最底层存value即可
      const z = new SkipListNode<T>(key, null)

      z.left = p
      z.right = p.right
      if (p.right) {
        p.right.left = z
      }
      p.right = z

      z.down = q
      q.up = z

      q = z
      i = i + 1
    }
    this.size++
  }

  public get(key: number): T | null {
    const p = this.findNode(key)
    return p.key === key ? p.value : null
  }

  public remove(key: number) {
    let p: SkipListNode<T> | undefined = this.findNode(key)
    if (p.key !== key) return

    while (p != null) {
      p.left!.right = p.right
      p.right!.left = p.left
      p = p.up
    }
  }

  private addEmptyLevel() {

    const p1: SkipListNode<T> = new SkipListNode(SkipListNode.negInf, null)
    const p2: SkipListNode<T> = new SkipListNode(SkipListNode.posInf, null)

    p1.right = p2
    p1.down = this.head

    p2.left = p1
    p2.down = this.tail

    this.head.up = p1
    this.tail.up = p2

    this.head = p1
    this.tail = p2

    this.levelCount++
  }

  private findNode(key: number): SkipListNode<T> {
    const { head } = this
    let p = head
    while (true) {
      // 从左向右查找，直到右节点的key值大于要查找的key值
      while (p.right && p.right.key !== SkipListNode.posInf && p.right.key <= key) {
        p = p.right
      }
      // 如果有更低层的节点，则向低层移动
      if (p.down) {
        p = p.down
      } else {
        break
      }
    }
    // 这里返回的p的key值，是小于等于要找的key值的
    return p
  }
}

export class SkipListNode<T> {
  key: number
  value: T | null
  up?: SkipListNode<T>
  down?: SkipListNode<T>
  left?: SkipListNode<T>
  right?: SkipListNode<T>

  constructor(key: number, value: T | null) {
    this.key = key
    this.value = value
  }

  // 最小的数，无限接近于0，用于表示左标兵
  static negInf: number = Number.MIN_VALUE
  // 最大的数，用于表示右标兵
  static posInf: number = Number.MAX_VALUE
}

const testSkipList = new SkipList()
testSkipList.insert(12, 'qwe')
testSkipList.insert(3, 'mmm')
console.log(testSkipList.get(3))
