<?php
/**
 * Created by PhpStorm.
 * User: 764432054@qq.com
 * 堆的基本操作
 */

namespace Algo_10;

require_once '../vendor/autoload.php';
$arr=[50,3,60,70,45,20,100,0,58];

$heap=new Heap();
foreach ($arr as $v){
    $heap->insert($v);
}

while(($r=$heap->deleteFirst())!==null){
    echo $r." ";
}
echo PHP_EOL;

$heap1=new Heap(10);

foreach ($arr as $v){
    $heap1->insertOnly($v);
}



$heap1->heapAll();
//堆化后的
print_r($heap1->dataArr);
//堆排序
$heap1->heapSort();
print_r($heap1->dataArr);
