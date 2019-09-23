<?php
/**
 * Created by PhpStorm.
 * User: 764432054@qq.com
 * Date: 2019/9/5
 * Time: 9:01
 * 堆的基本操作(大顶堆，小顶堆 几种堆化方式，堆排序，动态数据流查top k ,查中位数)
 *
 */
namespace Algo_10;

class Heap
{
    public $dataArr = [];
    public $count = 0;
    public $size; //堆的大小 0表示不限制大小自动扩容
    public $heapType = 1; //1 表示大根堆  0表示小根堆

    public function __construct($size = 0, $heapType = 1)
    {
        $this->size = $size;
        $this->heapType = $heapType;
    }

    /**
     * @param $data
     * 插入并堆化
     */
    public function insert($data)
    {
        if ($this->isFull()) {
            return false;
        }
        $this->dataArr[$this->count + 1] = $data;
        $this->count++;
        if ($this->heapType) {
            $this->bigHeapLast();
        } else {
            $this->smallHeapLast();
        }
    }

    /**
     * @return bool
     * 堆是否满
     */
    public function isFull()
    {
        if ($this->size == 0) {
            return false;
        }
        if ($this->count >= $this->size) {
            return true;
        }
        return false;
    }
    public function isEmpty(){
        return empty($this->count)?true:false;
    }
    //返回堆顶的元素
    public function peak(){
        if($this->isEmpty()){
            return null;
        }
        return $this->dataArr[1];
    }


    //只插入
    public function insertOnly($data)
    {
        if ($this->isFull()) {
            return false;
        }
        $this->dataArr[$this->count + 1] = $data;
        $this->count++;
    }


    /**
     * 删除堆顶的元素
     * 把最后1个元素插入到堆顶
     * 然后从堆顶开始堆化
     * 返回堆化后的堆顶元素
     */
    public function deleteFirst()
    {
        $first = $this->dataArr[1];
        $last = array_pop($this->dataArr);
        if($this->isEmpty()){
            return null;
        }
        $this->count--;
        $i = 1;
        $this->dataArr[$i] = $last;
        if ($this->heapType) {
            $this->bigHeapFirst();
        } else {
            $this->smallHeapFirst();
        }
        return $first;

    }

    /**
     * 从某一个结点开始向下堆化
     */
    protected function heapFromOneToDown($i)
    {
        //大根堆
        if ($this->heapType) {
            $maxPos = $i;
            while (true) {
                if (2 * $i <= $this->count) {
                    if ($this->dataArr[$maxPos] < $this->dataArr[2 * $i]) {
                        $maxPos = 2 * $i;
                    }
                }
                if (2 * $i + 1 <= $this->count) {
                    if ($this->dataArr[$maxPos] < $this->dataArr[2 * $i + 1]) {
                        $maxPos = 2 * $i + 1;
                    }
                }
                //不需要交换
                if ($i == $maxPos) {
                    break;
                }
                $tmp = $this->dataArr[$maxPos];
                $this->dataArr[$maxPos] = $this->dataArr[$i];
                $this->dataArr[$i] = $tmp;
                //继续往下堆化
                $i = $maxPos;

            }
        } else {
            //小根堆
            $minPos = $i;
            while (true) {
                if (2 * $i <= $this->count) {
                    if ($this->dataArr[$minPos] > $this->dataArr[2 * $i]) {
                        $minPos = 2 * $i;
                    }
                }
                if (2 * $i + 1 <= $this->count) {
                    if ($this->dataArr[$minPos] > $this->dataArr[2 * $i + 1]) {
                        $minPos = 2 * $i + 1;
                    }
                }
                //不需要交换
                if ($i == $minPos) {
                    break;
                }
                $tmp = $this->dataArr[$minPos];
                $this->dataArr[$minPos] = $this->dataArr[$i];
                $this->dataArr[$i] = $tmp;
                //继续往下堆化
                $i = $minPos;

            }
        }

    }


    /**
     * 对于1个完全不符合堆性质的 整体堆化
     */
    public function heapAll()
    {
        for ($i = intval($this->count / 2); $i >= 1; $i--) {
            $this->heapFromOneToDown($i);
        }
    }

    /**
     * 堆排序
     * 把堆顶部的元素和数组尾部元素交换
     */
    public function heapSort()
    {
        $sorted = 0;//已经有序的个数
        while ($sorted < $this->count) {
            $i = 1;
            $head = $this->dataArr[$i];
            $this->dataArr[$i] = $this->dataArr[$this->count - $sorted];
            $this->dataArr[$this->count - $sorted] = $head;
            $sorted++;

            while (true) {
                $maxPos = $i;
                if (2 * $i <= $this->count - $sorted && $this->dataArr[$maxPos] < $this->dataArr[2 * $i]) {
                    $maxPos = 2 * $i;
                }
                if (2 * $i + 1 <= $this->count - $sorted && $this->dataArr[$maxPos] < $this->dataArr[2 * $i + 1]) {
                    $maxPos = 2 * $i + 1;
                }
                if ($i == $maxPos) {
                    break;
                }
                $tmp = $this->dataArr[$i];
                $this->dataArr[$i] = $this->dataArr[$maxPos];
                $this->dataArr[$maxPos] = $tmp;
                $i = $maxPos;
            }
        }

    }

    /**
     *小顶堆 堆化
     * 插入时
     * 堆化最后1个元素
     */
    public function smallHeapLast()
    {
        $i = $this->count;
        while (true) {
            $smallPos = $i;
            $parent = intval($i / 2);
            if ($parent >= 1) {
                if ($this->dataArr[$smallPos] < $this->dataArr[$parent]) {
                    $smallPos = $parent;
                }
            }
            if ($smallPos == $i) {
                break;
            }
            $tmp = $this->dataArr[$smallPos];
            $this->dataArr[$smallPos] = $this->dataArr[$i];
            $this->dataArr[$i] = $tmp;
            $i = $smallPos;
        }
    }

    /**
     * 小根堆
     * 堆化根部元素(第一个元素)
     */
    public function smallHeapFirst()
    {
        $i = 1;
        while (true) {
            $smallpos = $i;
            $left = 2 * $i;
            if ($left <= $this->count) {
                if ($this->dataArr[$smallpos] > $this->dataArr[$left]) {
                    $smallpos = $left;
                }
            }
            $right = $left + 1;
            if ($right <= $this->count) {
                if ($this->dataArr[$smallpos] > $this->dataArr[$right]) {
                    $smallpos = $right;
                }
            }
            if ($smallpos == $i) {
                break;
            }
            $tmp = $this->dataArr[$i];
            $this->dataArr[$i] = $this->dataArr[$smallpos];
            $this->dataArr[$smallpos] = $tmp;
            $i = $smallpos;
        }

    }

    /**
     * 大根堆
     * 堆化根部元素(第一个元素)
     */
    public function bigHeapFirst()
    {
        $i = 1;
        while (true) {
            $maxpos = $i;
            $left = 2 * $i;
            if ($left <= $this->count) {
                if ($this->dataArr[$maxpos] < $this->dataArr[$left]) {
                    $maxpos = $left;
                }
            }
            $right = $left + 1;
            if ($right <= $this->count) {
                if ($this->dataArr[$maxpos] < $this->dataArr[$right]) {
                    $maxpos = $right;
                }
            }
            if ($maxpos == $i) {
                break;
            }
            $tmp = $this->dataArr[$i];
            $this->dataArr[$i] = $this->dataArr[$maxpos];
            $this->dataArr[$maxpos] = $tmp;
            $i = $maxpos;
        }

    }
    //大根堆，  插入节点后放到数组最后面，然后从插入的节点自下而上开始堆化
    //这里只堆化插入元素相关的节点(就是说，如果没插入这个元素，这个是一个堆)
    public function bigHeapLast()
    {
        $i = $this->count;
        while (intval($i / 2) > 0 && $this->dataArr[$i] > $this->dataArr[intval($i / 2)]) {
            $tmp = $this->dataArr[$i];
            $this->dataArr[$i] = $this->dataArr[intval($i / 2)];
            $this->dataArr[intval($i / 2)] = $tmp;
            $i = $i / 2;
        }
    }

    /**
     * @param $data
     */
    public function topn($data)
    {
        //堆满了
        if ($this->isFull()) {
            if ($data > $this->dataArr[1]) {
                $this->dataArr[1] = $data;
                $this->smallHeapFirst();
            }
        } else {
            $this->dataArr[$this->count + 1] = $data;
            $this->count++;
            $this->smallHeapLast();

        }
        return $this->dataArr[1];

    }



}




