<?php
/**
 * User: lide01
 * Date: 2018/10/11 19:37
 * Desc:
 */

namespace Algo_08;


use Algo_06\SingleLinkedListNode;

class StackOnLinkedList
{
    /**
     * 头指针
     *
     * @var SingleLinkedListNode
     */
    public $head;

    /**
     * 栈长度
     *
     * @var
     */
    public $length;

    /**
     *
     * StackOnLinkedList constructor.
     */
    public function __construct()
    {
        $this->head = new SingleLinkedListNode();
        $this->length = 0;
    }

    /**
     * 出栈
     *
     * @return bool
     */
    public function pop()
    {
        if (0 == $this->length) {
            return false;
        }

        $this->head->next = $this->head->next->next;
        $this->length--;

        return true;
    }

    /**
     * 入栈
     *
     * @param $data
     *
     * @return SingleLinkedListNode|bool
     */
    public function push($data)
    {
        return $this->pushData($data);
    }

    /**
     * 入栈 node
     *
     * @param SingleLinkedListNode $node
     *
     * @return bool
     */
    public function pushNode(SingleLinkedListNode $node)
    {
        if (null == $node) {
            return false;
        }

        $node->next = $this->head->next;
        $this->head->next = $node;

        $this->length++;
        return true;
    }

    /**
     * 入栈 data
     *
     * @param $data
     *
     * @return SingleLinkedListNode|bool
     */
    public function pushData($data)
    {
        $node = new SingleLinkedListNode($data);

        if (!$this->pushNode($node)) {
            return false;
        }

        return $node;
    }

    /**
     * 获取栈顶元素
     *
     * @return SingleLinkedListNode|bool|null
     */
    public function top()
    {
        if (0 == $this->length) {
            return false;
        }

        return $this->head->next;
    }

    /**
     * 打印栈
     */
    public function printSelf()
    {
        if (0 == $this->length) {
            echo 'empty stack' . PHP_EOL;
            return;
        }

        echo 'head.next -> ';
        $curNode = $this->head;
        while ($curNode->next) {
            echo $curNode->next->data . ' -> ';

            $curNode = $curNode->next;
        }
        echo 'NULL' . PHP_EOL;
    }

    /**
     * 获取栈长度
     *
     * @return int
     */
    public function getLength()
    {
        return $this->length;
    }

    /**
     * 判断栈是否为空
     *
     * @return bool
     */
    public function isEmpty()
    {
        return $this->length > 0 ? false : true;
    }
}