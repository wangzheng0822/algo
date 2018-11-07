<?php
/**
 * User: lide01
 * Date: 2018/10/8 11:38
 * Desc:
 */

namespace Algo_06;


/**
 * 单链表节点
 *
 * Class SingleLinkedListNode
 *
 * @package Algo_06
 */
class SingleLinkedListNode
{
    /**
     * 节点中的数据域
     *
     * @var null
     */
    public $data;

    /**
     * 节点中的指针域，指向下一个节点
     *
     * @var SingleLinkedListNode
     */
    public $next;

    /**
     * SingleLinkedListNode constructor.
     *
     * @param null $data
     */
    public function __construct($data = null)
    {
        $this->data = $data;
        $this->next = null;
    }
}