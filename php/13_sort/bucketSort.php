<?php

require_once '../12_sort/quickSort.php';


$numbers = [11,23,45,67,88,99,22,34,56,78,90,12,34,5,6,91,92,93,93,94,95,94,95,96,97,98,99,100];
$size = 10;
var_dump(bucketSort($numbers));//加载了quickSort文件，请忽略前几个打印


/**
 * 桶排序
 * 假设一个桶只能放置10个元素
 * 当一个桶内元素过多，需要继续分桶
 * @param array $numbers
 * @param [type] $size
 *
 * @return void
 * @date 2018/11/25
 * @author yuanliandu 
 */
function bucketSort(array $numbers) {
    $min = min($numbers);
    $max = max($numbers);
    $length = count($numbers);
    $bucketNumber =  ceil(($max-$min)/$length) + 1;
    $buckets = [];
    foreach($numbers as $key => $value) {
        $index = ceil(($value-$min)/$length);
        $buckets[$index][] = $value; 
    }
    
    $result = [];
    for($i=0;$i<$bucketNumber;$i++) {
        $bucket = $buckets[$i];
        $length = count($bucket);
        //如果桶内元素为空，跳过这个桶
        if($length == 0) {
            continue;
        }
        if( $length > 10) {
            $bucket = bucketSort($bucket);
        }

       quickSort($bucket,0,count($bucket)-1);
       $result = array_merge($result,$bucket);
   }
   return $result;
}

