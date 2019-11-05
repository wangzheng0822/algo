<?php

namespace Algo_24;

class Tree
{

    /**
     * 树的根节点
     * @var [type]
     */
    public $head = null;

    /**
     * [__construct description]
     * @param TreeNode|null $head [description]
     */
    public function __construct($headData = null)
    {
        if ($headData != null) {
            $this->head = new TreeNode($headData);
        }
    }

    /**
     * 查找数据
     * @param  [type] $data [数据]
     * @return [type]       [description]
     */
    public function find($data)
    {
        if ($this->head == null) {
            return null;
        }

        $node = $this->head;

        while ($node != null) {
            if ($node->data == $data) {
                return $node;
            } elseif ($data > $node->data) {
                $node = $node->right;
            } else {
                $node = $node->left;
            }
        }

        return null;
    }

    /**
     * 插入数据
     * @param  [type] $data [数据]
     * @return [type]       [description]
     */
    public function insert($data)
    {
        if ($this->head == null) {
            $this->head = new TreeNode($data);
            return true;
        }

        $node = $this->head;

        while ($node != null) {
            if ($data > $node->data) {
                if ($node->right == null) {
                    $node->right = new TreeNode($data);
                    return true;
                }
                $node = $node->right;
            } else {
                if ($node->left == null) {
                    $node->left = new TreeNode($data);
                    return true;
                }
                $node = $node->left;
            }
        }
    }

    /**
     * 删除节点
     * @param  [type] $data [节点]
     * @return [type]       [description]
     */
    public function delete($data)
    {
        // 找到需要删除节点
        $node = $this->head;
        $pnode = null;
        while ($node != null) {
            if ($node->data == $data) {
                break;
            } elseif ($data > $node->data) {
                $pnode = $node;
                $node = $node->right;
            } else {
                $pnode = $node;
                $node = $node->left;
            }
        }        
        if ($node == null) {
            return false;
        }
        // 要删除的节点有两个子节点
        // 查找右子树中最小节点
        if ($node->left != null && $node->right != null) {
            $minPP = $node;
            $minP = $node->right;
            while ($minP->left != null) {
                $minPP = $minP;
                $minP = $minP->left;
            }
            $node->data = $minP->data;
            $node = $minP;
            // 删除掉右子树中的最小节点
            $minPP->left = null;
        }

        if ($node->left != null) {
            $child = $node->left;
        } elseif ($node->right != null) {
            $child = $node->right;
        } else {
            $child = null;
        }

        if ($pnode == null) {
            // 删除的是根节点
            $node = $child;
        } elseif ($pnode->left == $node) {
            $pnode->left = $child;
        } else {
            $pnode->right = $child;
        }
    }

    /**
     * 前序遍历
     * @return [type] [description]
     */
    public function preOrder($node)
    {
        if ($node == null) {
            return ;            
        }
        echo $node->data . '->';
        $this->preOrder($node->left);
        $this->preOrder($node->right);
    }

    /**中序遍历
     * @param $node
     *
     */
    public function inOrder($node){
        if(empty($node)){
            return;
        }
        $this->inOrder($node->left);
        echo $node->data . ' ';
        $this->inOrder($node->right);

    }

    /**
     * @param $node
     * 后续遍历
     */
    public function postOrder($node){
        if(empty($node)){
            return;
        }
        $this->postOrder($node->left);
        $this->postOrder($node->right);
        echo $node->data . ' ';

    }
    /**
     * @param $queue
     * @param int $index 从队列(数组)的那个位置开始处理
     * 层级遍历
     * 首先把节点放入数组，记录放入数组的根节点个数index，把节点的左右子放入数组
     * 开始遍历数组queue(从index开始,子节点已经入队列的节点元素不再处理)，把左右子节点放入queue,index++
     * 持续上述过程，当节点没有子节点时，入队列过程结束，queue里节点的顺序即为层级遍历元素节点的顺序
     *
     * 完全二叉树
     */
    public function levelOrder($queue, $index = 0)
    {
        for ($i = $index; $i < count($queue); $i++) {
            $node = $queue[$i];
            if ($node->left) {
                $queue[] = $node->left;
            } else {
                return $queue;
            }
            if ($node->right) {
                $queue[] = $node->right;
            } else {
                return $queue;
            }
            $index++;
        }
        return $queue;

    }
}