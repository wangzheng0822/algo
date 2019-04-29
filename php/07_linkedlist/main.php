<?php
/**
 * User: lide01
 * Date: 2018/10/9 14:06
 * Desc:
 */

namespace Algo_07;
require_once '../vendor/autoload.php';

use Algo_06\SingleLinkedList;


/**
 * 单链表相关算法
 *
 * Class SingleLinkedListAlgo
 *
 * reverse 单链表反转
 * checkCircle 链表中环的检测
 * mergerSortedList 两个有序的链表合并
 * deleteLastKth 删除链表倒数第n个结点
 * findMiddleNode 求链表的中间结点
 *
 * @package Algo_07
 */
Class SingleLinkedListAlgo
{
    /**
     * 单链表
     *
     * @var
     */
    public $list;

    /**
     * 构造函数设置$list
     *
     * SingleLinkedListAlgo constructor.
     *
     * @param SingleLinkedList $list
     */
    public function __construct(SingleLinkedList $list = null)
    {
        $this->list = $list;
    }

    /**
     * 设置单链表
     *
     * @param SingleLinkedList $list
     */
    public function setList(SingleLinkedList $list)
    {
        $this->list = $list;
    }

    /**
     * 单链表反转
     *
     * 三个指针反转
     * preNode 指向前一个结点
     * curNode 指向当前结点
     * remainNode 指向当前结点的下一个节点（保存未逆序的链表，为了在断开curNode的next指针后能找到后续节点）
     *
     * @return bool
     */
    public function reverse()
    {
        if (null == $this->list || null == $this->list->head || null == $this->list->head->next) {
            return false;
        }

        $preNode = null;
        $curNode = $this->list->head->next;
        $remainNode = null;

        // 保存头结点，稍后指向反转后的链表
        $headNode = $this->list->head;
        // 断开头结点的next指针
        $this->list->head->next = null;

        while ($curNode != null) {
            $remainNode = $curNode->next;
            $curNode->next = $preNode;
            $preNode = $curNode;
            $curNode = $remainNode;
        }

        // 头结点指向反转后的链表
        $headNode->next = $preNode;

        return true;
    }

    /**
     * 判断链表是否有环
     *
     * 快慢指针判断是否有环
     * @link http://t.cn/ROxpgQ1
     *
     * @return bool
     */
    public function checkCircle()
    {
        if (null == $this->list || null == $this->list->head || null == $this->list->head->next) {
            return false;
        }

        $slow = $this->list->head->next;
        $fast = $this->list->head->next;

        while ($fast != null && $fast->next != null) {
            $fast = $fast->next->next;
            $slow = $slow->next;

            // 如果慢指针跟快指针相遇了说明有环 解释在上面的链接中
            if ($slow === $fast) {
                return true;
            }
        }

        return false;
    }

    /**
     * 合并两个有序链表
     *
     * @param SingleLinkedList $listA
     * @param SingleLinkedList $listB
     *
     * @return SingleLinkedList|\Algo_06\SingleLinkedListNode
     */
    public function mergerSortedList(SingleLinkedList $listA, SingleLinkedList $listB)
    {
        if (null == $listA) {
            return $listB;
        }
        if (null == $listB) {
            return $listA;
        }

        $pListA = $listA->head->next;
        $pListB = $listB->head->next;
        $newList = new SingleLinkedList();
        $newHead = $newList->head;
        $newRootNode = $newHead;

        while ($pListA != null && $pListB != null) {
            if ($pListA->data <= $pListB->data) {
                $newRootNode->next = $pListA;
                $pListA = $pListA->next;
            } else {
                $newRootNode->next = $pListB;
                $pListB = $pListB->next;
            }

            $newRootNode = $newRootNode->next;
        }

        // 如果第一个链表未处理完，拼接到新链表后面
        if ($pListA != null) {
            $newRootNode->next = $pListA;
        }
        // 如果第二个链表未处理完，拼接到新链表后面
        if ($pListB != null) {
            $newRootNode->next = $pListB;
        }

        return $newList;
    }

    /**
     * 删除链表倒数第n个结点
     *
     * @param $index
     *
     * @return bool
     */
    public function deleteLastKth($index)
    {
        if (null == $this->list || null == $this->list->head || null == $this->list->head->next) {
            return false;
        }

        $i = 1;
        $slow = $this->list->head;
        $fast = $this->list->head;
        while ($fast != null && $i < $index) {
            $fast = $fast->next;
            ++$i;
        }

        if (null == $fast) {
            return true;
        }

        $pre = null;
        while($fast->next != null) {
            $pre = $slow;
            $slow = $slow->next;
            $fast = $fast->next;
        }

        if (null == $pre) {
            $this->list->head->next = $slow->next;
        } else {
            $pre->next = $pre->next->next;
        }

        return true;
    }

    /**
     * 寻找中间节点
     *
     * 快慢指针遍历
     *
     * @return \Algo_06\SingleLinkedListNode|bool|null
     */
    public function findMiddleNode()
    {
        if (null == $this->list || null == $this->list->head || null == $this->list->head->next) {
            return false;
        }

        $slow = $this->list->head->next;
        $fast = $this->list->head->next;

        while ($fast != null && $fast->next != null) {
            $fast = $fast->next->next;
            $slow = $slow->next;
        }

        return $slow;
    }
}

echo '---------------------- 单链表反转 ----------------------' . PHP_EOL . PHP_EOL;
$list = new SingleLinkedList();
$list->insert(1);
$list->insert(2);
$list->insert(3);
$list->insert(4);
$list->insert(5);
$list->insert(6);
$list->insert(7);

// 单链表反转
$listAlgo = new SingleLinkedListAlgo($list);
$listAlgo->list->printList();
$listAlgo->reverse();
$listAlgo->list->printList();
echo '--------------------------------------------------------' . PHP_EOL . PHP_EOL;

echo '---------------------- 链表中环的检测 ----------------------'. PHP_EOL . PHP_EOL;
// 链表中环的检测
$listCircle = new SingleLinkedList();
$listCircle->buildHasCircleList();
$listAlgo->setList($listCircle);
var_dump($listAlgo->checkCircle());
echo '------------------------------------------------------------' . PHP_EOL . PHP_EOL;

echo '---------------------- 两个有序的链表合并 ----------------------' . PHP_EOL . PHP_EOL;
// 两个有序的链表合并
$listA = new SingleLinkedList();
$listA->insert(9);
$listA->insert(7);
$listA->insert(5);
$listA->insert(3);
$listA->insert(1);
$listA->printList();

$listB = new SingleLinkedList();
$listB->insert(10);
$listB->insert(8);
$listB->insert(6);
$listB->insert(4);
$listB->insert(2);
$listB->printList();

$listAlgoMerge = new SingleLinkedListAlgo();
$newList = $listAlgoMerge->mergerSortedList($listA, $listB);
$newList->printListSimple();
echo '----------------------------------------------------------------'. PHP_EOL . PHP_EOL;

echo '---------------------- 删除链表倒数第n个结点 ----------------------' . PHP_EOL . PHP_EOL;
// 删除链表倒数第n个结点
$listDelete = new SingleLinkedList();
$listDelete->insert(1);
$listDelete->insert(2);
$listDelete->insert(3);
$listDelete->insert(4);
$listDelete->insert(5);
$listDelete->insert(6);
$listDelete->insert(7);
$listDelete->printList();
$listAlgo->setList($listDelete);
$listAlgo->deleteLastKth(3);
var_dump($listAlgo->list->printListSimple());
echo '------------------------------------------------------------------'. PHP_EOL . PHP_EOL;

echo '---------------------- 求链表的中间结点 ----------------------' . PHP_EOL . PHP_EOL;
// 求链表的中间结点
$listAlgo->setList($list);
$middleNode = $listAlgo->findMiddleNode();
var_dump($middleNode->data);
echo '-------------------------------------------------------------'. PHP_EOL . PHP_EOL;
