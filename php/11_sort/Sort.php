<?php

function insertionSort(&$arr)
{
    $n = count($arr);
    if ($n <= 1) return;

    for ($i = 1; $i < $n; ++$i) {
        $value = $arr[$i];
        $j = $i - 1;
        // 查找插入的位置
        for (; $j >= 0; --$j) {
            if ($arr[$j] > $value) {
                $arr[$j + 1] = $arr[$j];  // 数据移动
            } else {
                break;
            }
        }
        $arr[$j + 1] = $value; // 插入数据
    }
}

$arr = [1,4,6,2,3,5,4];
insertionSort($arr);
var_dump($arr);
