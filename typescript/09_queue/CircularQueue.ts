/**
 * 基于数组的循环队列
 * 为了方便判断队列为空的情况，这里最好引入元素个数
 */
class CircularQueue<T> {
  private items: T[] = []
  private readonly n: number = 0
  private head: number = 0
  private tail: number = 0
  // 队列的实际元素大小
  size: number = 0


  constructor(capacity: number) {
    this.n = capacity
  }

  public enqueue(item: T): boolean {
    // 表示队列已经满了
    if (this.size === this.n) return false
    this.items[this.tail] = item
    this.tail = (this.tail + 1) % this.n
    this.size++
    return true
  }

  public dequeue(): T | null {
    if (!this.size) return null
    const item = this.items[this.head]
    this.head = (this.head + 1) % this.n
    this.size--
    return item
  }
}

const circularQueue = new CircularQueue<number>(3)
circularQueue.enqueue(1)
circularQueue.enqueue(2)
circularQueue.enqueue(3)
circularQueue.enqueue(4)

const value = circularQueue.dequeue()
const value1 = circularQueue.dequeue()
const value2 = circularQueue.dequeue()
const value3 = circularQueue.dequeue()

// null
console.log(value3)
// 0
console.log(circularQueue.size)

