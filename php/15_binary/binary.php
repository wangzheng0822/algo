<?php


/**
 * 二分查找 查找=find的元素
 * @param array $numbers
 * @param [type] $find
 *
 * @return void
 * @date 2018/11/26
 * @author yuanliandu 
 */
function binarySearch(array $numbers, $find)
{
    $low = 0;
    $high = count($numbers) - 1;
    return search($numbers, $low, $high, $find);
}

function search(array $numbers, $low, $high, $find)
{
    /**
     * notice1 循环退出条件
     */
    if ($low > $high) {
        return -1;
    }

    /**
     * notice2 mid计算
     */
    $mid = $low + (($high - $low) >> 1);
    if ($numbers[$mid] > $find) {
        //notice3 high值更新
        return search($numbers, $low, $mid -1, $find);
    } elseif ($numbers[$mid] < $find) {
        //notice4 low值更新
        return search($numbers, $mid + 1, $high, $find);
    } else {
        return $mid;
    }
}

/**
 * 求数字的平方根，保留6位小数
 * @param [type] $number
 *
 * @return void
 * @date 2018/11/26
 * @author yuanliandu 
 */
function squareRoot($number)
{
    if ($number < 0) {
        return  -1;
    } elseif ($number < 1) {
        $min = $number;
        $max = 1;
    } else {
        $min = 1;
        $max = $number;
    }
    $mid = $min + ($max - $min) / 2;
    while (getDecimalPlaces($mid) < 6) {
        $square = $mid * $mid;
        if ($square > $number) {
            $max = $mid;
        } elseif ($square == $number) {
            return $mid;
        } else {
            $min = $mid;
        }
        $mid = $min + ($max - $min) / 2;
    }
    return $mid;
}

/**
 * 计算数字小数点后有几位数字
 * @param [type] $number
 *
 * @return void
 * @date 2018/11/27
 * @author yuanliandu <yuanliandu@qq.com>
 */
function getDecimalPlaces($number)
{
    $temp = explode('.', $number);
    if (isset($temp[1])) {
        return strlen($temp[1]);
    }

    return 0;
}

// 测试二分查找给定值
$numbers = [0, 1, 2, 3, 3, 4, 5, 6, 7, 9];
$find = 1;
var_dump(binarySearch($numbers,$find));

//测试求平方根
var_dump(squareRoot(3));