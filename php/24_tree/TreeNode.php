<?php

namespace Algo_24;

class TreeNode
{

    /**
     * 节点中的数据
     * @var [type]
     */
    public $data;

    /**
     * 左节点
     * @var [type]
     */
    public $left;

    /**
     * 右节点
     * @var [type]
     */
    public $right;

    /**
     * [__construct description]
     * @param [type] $data [description]
     */
    public function __construct($data = null)
    {
        $this->data = $data;
        $this->left = null;
        $this->right = null;
    }
}