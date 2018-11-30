<?php

/**
 * 计数排序
 * 五分制
 * 13个人
 */
$score = [0,1,5,3,2,4,1,2,4,2,1,4,4];

var_dump(countingSort($score));die();
function countingSort(array $score) {

    $length = count($score);
    if($length <= 1) {return $score;}
    
    /**
     * 统计每个分数的人数
     */
    $temp = [];
    $countScore = [];
    foreach ($score as $key => $value) {
        $countScore[$value]++;
    }
    
    /**
     * 顺序求和
     */
    for($i=1;$i<=5;$i++) {
        $countScore[$i] += $countScore[$i-1];
    }
    /**
     * 排序
     */
    foreach ($score as $key => $value) {
        $countScore[$value] --;
        $temp[$countScore[$value]] = $value;
    }
    //copy
    for($i=0;$i<$length;$i++) {
        $score[$i] = $temp[$i];
    }
    return $score;
}