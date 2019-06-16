/**
 * 二叉树的增删查操作
 */
export class TreeSearch {
  private root?: Node

  public find(data: number) {
    let p = this.root
    while (p != null) {
      if (data < p.data) {
        p = p.left
      } else if (data > p.data) {
        p = p.right
      } else {
        return p
      }
    }
    return p
  }

  public insert(data: number) {
    if (this.root == null) {
      this.root = new Node(data)
      return
    }
    let p = this.root
    while (p != null) {
      if (data < p.data) {
        if (p.left == null) {
          p.left = new Node(data)
          return
        } else {
          p = p.left
        }
      } else {
        if (data > p.data) {
          if (p.right == null) {
            p.right = new Node(data)
            return
          } else {
            p = p.right
          }
        }
      }
    }
  }

  /**
   * 删除的时候分三种情况
   * @param data
   */
  public delete(data: number) {
    // 先把对应的元素找出来,并且为了删除，也得记录父节点的内存地址
    // 包含了null或者undefined两种情况
    if (this.root == null) return
    let p: Node | undefined = this.root
    let pp = this.root
    while (p != null && p.data !== data) {
      pp = p
      data > p.data ? p = p.right : p = p.left
    }
    // 没有找到要删除的元素
    if (p == null) return
    // 要删除的元素有两个子节点,需要找到右子树的最小节点，然后赋值
    if (p.left != null && p.right != null) {
      // 右子树的最小节点
      let minP = p.right
      // 右子树的最小节点的父节点
      let minPP = p
      while (minP.left != null) {
        minPP = minP
        minP = minP.left
      }
      p.data = minP.data
      p = minP
      pp = minPP
    }

    // 有一个子节点或者没有子节点
    let child
    if (p.left != null) {
      child = p.left
    } else if (p.right != null) {
      child = p.right
    } else {
      child = null
    }
    if (pp == null) {
      this.root = undefined
    } else if (pp.left === p) {
      pp.left = child!
    } else {
      pp.right = child!
    }
  }

  public printAllData(): void {
    this.printAll(this.root)
  }

  private printAll(node?: Node): void {
    if (node == null) return
    console.log(node.data)
    this.printAll(node.left)
    this.printAll(node.right)
  }
}

export class Node {
  data: number
  left?: Node
  right?: Node

  constructor(data: number) {
    this.data = data
  }
}

const treeSearch = new TreeSearch()
treeSearch.insert(1)
treeSearch.insert(4)
treeSearch.insert(3)
treeSearch.insert(2)
treeSearch.insert(5)
treeSearch.insert(0)

treeSearch.delete(4)

treeSearch.printAllData()
