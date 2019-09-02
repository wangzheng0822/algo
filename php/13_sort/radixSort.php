<?php

/**
 * 基数排序
 * 先根据个位排序、百位、千位........
 */
$numbers = [
    1234,
    4321,
    12,
    31,
    412,
];
$max = (string) max($numbers);//求出最大数字
$loop =  strlen($max);//计算最大数字的长度，决定循环次数

for($i=0;$i<$loop;$i++) {
    radixSort($numbers,$i);
}
var_dump($numbers);

/**
 * 基数排序
 * @param array $numbers
 * @param [type] $loop
 *
 * @return void
 * @date 2018/11/26
 * @author yuanliandu 
 */
function radixSort(array &$numbers,$loop) {

    $divisor = pow(10,$loop);//除数  主要决定比较个位数、百位.....
    $buckets = (new \SplFixedArray(10))->toArray();
    foreach ($numbers as $key => $value) {
        $index = ($value/$divisor)%10;//计算该数字在哪个桶中
        $buckets[$index][] = $value;
    }
    /**
     * 从桶中取出数字
     */
    $k=0;
    for($i=0;$i<10;$i++) {
        while(count($buckets[$i]) > 0) {
            $numbers[$k++] = array_shift($buckets[$i]);
        }
    }
}
