<?php
// 冒泡排序
function bubbleSort(&$arr)
{
    $length = count($arr);
    if ($length <= 1) return;

    for ($i = 0; $i < $length; $i++) {
        $flag = false;
        for ($j = 0; $j < $length - $i - 1; $j++) {
            if ($arr[$j] > $arr[$j + 1]) {
                $tmp = $arr[$j];
                $arr[$j] = $arr[$j + 1];
                $arr[$j + 1] = $tmp;
                $flag = true;
            }
        }
        if (!$flag) {
            break;
        }
    }
}

// 插入排序
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

// 选择排序
function selectionSort(&$arr)
{
    $length = count($arr);
    if ($length <= 1) return;

    for ($i = 0; $i < $length - 1; $i++) {
        //先假设最小的值的位置
        $p = $i;
        for ($j = $i + 1; $j < $length; $j++) {
            if ($arr[$p] > $arr[$j]) {
                $p = $j;
            }
        }
        $tmp = $arr[$p];
        $arr[$p] = $arr[$i];
        $arr[$i] = $tmp;
    }
}

$arr = [1,4,6,2,3,5,4];
insertionSort($arr);
var_dump($arr);
