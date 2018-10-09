<?php
/**
 * User: lide01
 * Date: 2018/10/8 11:55
 * Desc:
 */

namespace Algo_06;
require_once '../vendor/autoload.php';

/**
 * 判断链表保存的字符串是否是回文
 *
 * @param SingleLinkedList $list
 *
 * @return bool
 */
function isPalindrome(SingleLinkedList $list)
{
    if ($list->getLength() <= 1) {
        return true;
    }

    $pre = null;
    $slow = $list->head->next;
    $fast = $list->head->next;
    $remainNode = null;

    // 找单链表中点 以及 反转前半部分链表
    while ($fast != null && $fast->next != null) {
        $fast = $fast->next->next;

        // 单链表反转关键代码 三个指针
        $remainNode = $slow->next;
        $slow->next = $pre;
        $pre = $slow;
        $slow = $remainNode;
    }
    // 链表长度为偶数的情况
    if ($fast != null) {
        $slow = $slow->next;
    }

    // 开始逐个比较
    while ($slow != null) {
        if ($slow->data != $pre->data) {
            return false;
        }
        $slow = $slow->next;
        $pre = $pre->next;
    }

    return true;
}

$list = new SingleLinkedList();
$list->insert('a');
$list->insert('b');
$list->insert('c');
$list->insert('c');
$list->insert('b');
$list->insert('a');

var_dump(isPalindrome($list));