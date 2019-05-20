interface List<T> {
  insertToHead(value: T): void

  findByValue(value: T): any

  findByIndex(index: number): any

  insertToIndex(value: T, index: number): void

  remove(value: T): boolean

  insertToHead(value: T): void

  insertToTail(value: T): void

  toString(): string
}

export default List
