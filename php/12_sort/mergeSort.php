<?php
/*
 * 归并排序
 */

$arr = [4, 5, 6, 1, 3, 2];
$length = count($arr);

$p = 0;
$r = $length - 1;

$result = mergeSort($arr, $p, $r);

var_dump($result);


function mergeSort(array $arr, $p, $r)
{
    return mergeSortRecursive($arr, $p, $r);
}

// 递归调用函数
function mergeSortRecursive(array $arr, $p, $r)
{
    // 递归终止条件
    if ($p >= $r) {
        return [$arr[$r]];
    }

    // 取 p 到 r 之间的中间位置 q
    $q = (int)(($p + $r) / 2);

    // 分治递归
    $left = mergeSortRecursive($arr, $p, $q);
    $right = mergeSortRecursive($arr, $q + 1, $r);
    return merge($left, $right);
}

// 合并
function merge(array $left, array $right)
{
    $tmp = [];
    $i = $j = 0;

    $leftLength = count($left);
    $rightLength = count($right);

    do {
        if ($left[$i] <= $right[$j]) {
            $tmp[] = $left[$i++];
        } else {
            $tmp[] = $right[$j++];
        }
    } while ($i < $leftLength && $j < $rightLength);

    $start = $i;
    $end = $leftLength;
    $copyArr = $left;

    // 判断哪个子数组中有剩余的数据
    if ($j < $rightLength) {
        $start = $j;
        $end = $rightLength;
        $copyArr = $right;
    }

    // 将剩余的数据拷贝到临时数组 tmp
    do {
        $tmp[] = $copyArr[$start++];
    } while ($start < $end);

    return $tmp;
}