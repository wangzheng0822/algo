"""
    Binary search tree

    Author: Wenru Dong
"""
from typing import Optional

class TreeNode:
    def __init__(self, value: int):
        self.val = value
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self._root = None
    
    def find(self, value: int) -> Optional[TreeNode]:
        node = self._root
        while node and node.val != value:
            node = node.left if node.val > value else node.right
        return node
    
    def insert(self, value: int):
        if not self._root:
            self._root = TreeNode(value)
            return
        parent = None
        node = self._root
        while node:
            parent = node
            node = node.left if node.val > value else node.right
        new_node = TreeNode(value)
        if parent.val > value:
            parent.left = new_node
        else:
            parent.right = new_node

    def delete(self, value: int):
        node = self._root
        parent = None
        while node and node.val != value:
            parent = node
            node = node.left if node.val > value else node.right
        if not node: return
        
        # 要删除的节点有两个子节点
        if node.left and node.right:
            successor = node.right
            successor_parent = node
            while successor.left:
                successor_parent = successor
                successor = successor.left
            node.val = successor.val
            parent, node = successor_parent, successor
        
        # 删除节点是叶子节点或者仅有一个子节点
        child = node.left if node.left else node.right
        if not parent:
            self._root = child
        elif parent.left == node:
            parent.left = child
        else:
            parent.right = child
