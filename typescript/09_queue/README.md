### 队列

由于js语言天生就可以使用array数组来实现栈和队列等结构:
```javascript
  // 模拟数组队列
  const queue = []
  queue.push(1) // 向数组尾部添加数据
  queue.shift() //数组头部去除数据，并返回
```
这里我们使用链表来实现队列结构

队列分为无限队列和循环队列
