<?php

class SNode
{
    //数据域
    public $data;

    //指针域，引用SNode对象
    public $next = [];

    public function __construct($data = null)
    {
        $this->data = $data;
    }

    //获取当前节点索引层数
    public function getMaxLevel()
    {
        return count($this->next) - 1;
    }
}

class SkipList
{
    //索引最大层数
    public $indexLevel;

    //头节点
    protected $head;

    public function __construct(int $indexLevel)
    {
        $this->indexLevel = max($indexLevel, 0);
        $this->head = new SNode();
    }

    public function addData($data)
    {
        $newNode = new SNode($data);
        for ($level = $this->getRandomLevel(), $node = $this->head; $level >= 0; $level--) {
            while (isset($node->next[$level]) && $data < $node->next[$level]->data) {
                $node = $node->next[$level];
            }
            if (isset($node->next[$level])) {
                $newNode->next[$level] = $node->next[$level];
            }
            $node->next[$level] = $newNode;
        }
        return $newNode;
    }

    public function deleteData($data)
    {
        $deleted = false;
        for ($level = $this->head->getMaxLevel(), $node = $this->head; $level >= 0; $level--) {
            while (isset($node->next[$level]) && $data < $node->next[$level]->data) {
                $node = $node->next[$level];
            }
            if (isset($node->next[$level]) && $data == $node->next[$level]->data) {
                $node->next[$level] = isset($node->next[$level]->next[$level]) ?
                    $node->next[$level]->next[$level] : null;
                $deleted = true;
            }
        }
        return $deleted;
    }

    public function findData($data)
    {
        for ($level = $this->head->getMaxLevel(), $node = $this->head; $level >= 0; $level--) {
            while (isset($node->next[$level]) && $data < $node->next[$level]->data) {
                $node = $node->next[$level];
            }
            if (isset($node->next[$level]) && $data == $node->next[$level]->data) {
                return $node->next[$level];
            }
        }
        return false;
    }

    protected function getRandomLevel()
    {
        return mt_rand(0, $this->indexLevel);
    }
}

/**
 * 示例
 */

$indexLevel = 2;

$skipList = new SkipList($indexLevel);

for ($i = 10; $i >= 0; $i--) {
    $skipList->addData($i);
}

//打印0到10组成的跳表
var_dump($skipList);

//返回SNode对象
var_dump($skipList->findData(5));

$skipList->deleteData(5);

//返回false
var_dump($skipList->findData(5));