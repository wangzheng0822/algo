/**
 * 基于单向链表实现栈结构
 */
export class Stack<T> {
  private node: LinkedNode<T> | null = null
  size: number = 0

  public push(value: T) {
    if (!value) return
    const newNode = new LinkedNode(value)
    if (!this.node) {
      this.node = newNode
    } else {
      newNode.next = this.node
      this.node = newNode
    }
    this.size++
  }

  public pop(): T | null {
    if (!this.node) {
      return null
    }
    const value = this.node.value
    this.node = this.node.next
    this.size--
    return value
  }
}

/**
 * 单向链表
 */
class LinkedNode<T> {
  value: T
  next: LinkedNode<T> | null

  constructor(value: T, next: LinkedNode<T> | null = null) {
    this.value = value
    this.next = next
  }
}

/**
 * 使用双栈结构实现浏览器的前进后退
 */
class Browser<T> {
  // 存放后退的所有历史url
  private backStack: Stack<T>
  // 存放前进的所有url
  private forwardStack: Stack<T>
  private current: T

  constructor(current: T) {
    this.backStack = new Stack<T>()
    this.forwardStack = new Stack<T>()
    this.current = current
  }

  public back(): T | null {
    if (this.backStack.size > 0) {
      this.forwardStack.push(this.current)
      this.current = this.backStack.pop()!
      return this.getCurrentPage()
    }
    return null
  }

  public forward(): T | null {
    if (this.forwardStack.size > 0) {
      this.backStack.push(this.current)
      this.current = this.forwardStack.pop()!
      return this.getCurrentPage()
    }
    return null
  }

  /**
   * 在网页上点击一个链接
   * @param value
   */
  public linkUrl(value: T) {
    this.current && this.backStack.push(this.current)
    this.current = value
  }

  public getCurrentPage(): T {
    return this.current
  }
}

const browser = new Browser('www.baidu.com')
browser.linkUrl('www.yuanzhoucehui.com')
browser.linkUrl('www.github.com/jsrdxzw')
// browser.back()
// www.github.com/jsrdxzw
console.log(browser.getCurrentPage())
browser.back()
// www.yuanzhucehui.com
console.log(browser.getCurrentPage())
browser.back()
// www.baidu.com
console.log(browser.getCurrentPage())
browser.back()
// www.baidu.com
console.log(browser.getCurrentPage())
browser.forward()
// www.yuanzhucehui.com
console.log(browser.getCurrentPage())
browser.forward()
// www.github.com/jsrdxzw
console.log(browser.getCurrentPage())
