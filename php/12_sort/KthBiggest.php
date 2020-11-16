<?php

//查找第 k 大元素
class KthBiggest
{
    /**
     * 查找第 k 大元素
     *
     * @param array $arr
     * @param int $k 第 k 大
     *
     * @return int
     */
    public function kthBiggest($arr, $k)
    {
        $n = count($arr);

        if ($n == 0 || $k < 1 || $k > $n) {
            return null;
        }

        return $this->quickSort($arr, 0, $n-1, $k);
    }

    /**
     * 递归调用函数
     *
     * @param array $arr
     * @param int $p 起始下标
     * @param int $r 结束下标
     * @param int $k 第 k 大
     *
     * @return int
     */
    private function quickSort(&$arr, $p, $r, $k)
    {
        // 递归终止条件
        if ($p >= $r) {
            return $arr[$r];
        }

        // 获取分区点
        $q = $this->partition($arr, $p, $r);

        if ($q + 1 == $k) {
            return $arr[$q];
        } else if ($q + 1 > $k) {
            return $this->quickSort($arr, $p, $q-1, $k);
        } else {
            return $this->quickSort($arr, $q+1, $r, $k);
        }
    }

    /**
     * 获取分区点
     *
     * @param array $arr
     * @param int $p 起始下标
     * @param int $r 结束下标
     *
     * @return int
     */
    private function partition(&$arr, $p, $r)
    {
        $pivot = $arr[$r];
        $i = $p;

        for ($j = $p; $j < $r; $j++) {
            if ($arr[$j] > $pivot) {
                $this->swap($arr, $i, $j);
                $i++;
            }
        }

        $this->swap($arr, $i, $r);

        return $i;
    }
    
    /**
     * 值交换
     *
     * @param array $arr
     * @param int $a 数组下标
     * @param int $b 数组下标
     */
    private function swap(&$arr, $a, $b)
    {
        if ($a == $b) {
            return;
        }

        $tmp = $arr[$a];
        $arr[$a] = $arr[$b];
        $arr[$b] = $tmp;
    }
}
