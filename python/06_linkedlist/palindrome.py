"""
    check a single-linked list whether a palindrome
"""

import sys
# 引用当前文件夹下的single_linked_list
sys.path.append('singly_linked_list')
from singly_linked_list import SinglyLinkedList

def reverse(head):
    reverse_head = None
    while head:
        next = head._next
        head._next = reverse_head
        reverse_head = head
        head = next

    return reverse_head

def is_palindrome(l):
    l.print_all()
    slow = l._head
    fast = l._head
    position = 0
    while fast and fast._next:
        slow = slow._next
        fast = fast._next._next
        position += 1

    reverse_node = reverse(slow)
    head_node = l._head
    is_palin = True
    while (head_node and reverse_node):
        if (head_node.data == reverse_node.data):
            head_node = head_node._next
            reverse_node = reverse_node._next
        else:
            is_palin = False
            break

    return is_palin

if __name__ == '__main__':
    # the result should be False, True, True, True, True
    test_str_arr = ['ab', 'aa', 'aba', 'abba', 'abcba']
    for str in test_str_arr:
        l = SinglyLinkedList()
        for i in str:
            l.insert_value_to_head(i)

        print(is_palindrome(l))



