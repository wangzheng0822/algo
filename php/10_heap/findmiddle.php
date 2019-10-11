<?php
/**
 * Created by PhpStorm.
 * User: 764432054@qq.com
 * 动态数据流实时获取中位数
 */
namespace Algo_10;

require_once '../vendor/autoload.php';

$arr = [9, 8, 11, 4, 2, 6, 5, 1, -1, 3, 20, 10];
//$arr=[9,8,11,4,2,6,5,100];

findMiddle($arr);

//动态数据实时获取中位数
function findMiddle($arr)
{
    //大顶堆
    $bigHeap = new Heap(0, 1);
    //小顶堆
    $smallHeap = new Heap(0, 0);

    foreach ($arr as $k => $v) {
        if ($bigHeap->isEmpty()) {
            $bigHeap->insert($v);
        } else {
            $bigPeak = $bigHeap->peak();
            if ($v < $bigPeak) {
                $bigHeap->insert($v);
            } else {
                $smallHeap->insert($v);
            }

            if ($bigHeap->count - $smallHeap->count > 1) {
                $bigPeak = $bigHeap->deleteFirst();
                $smallHeap->insert($bigPeak);
            } elseif ($smallHeap->count - $bigHeap->count > 1) {
                $smallPeak = $smallHeap->deleteFirst();
                $bigHeap->insert($smallPeak);
            }

        }
        //实时获取中位数
        echo "现在的中位数为:".implode(',', midPeak($bigHeap, $smallHeap)) . PHP_EOL;
    }


}

function midPeak($heap1, $heap2)
{
    if ($heap1->count == $heap2->count) {
        $midArr = [$heap1->peak(), $heap2->peak()];
    } elseif ($heap2->count > $heap1->count) {
        $midArr = [$heap2->peak()];
    } else {
        $midArr = [$heap1->peak()];
    }
    return $midArr;
}
