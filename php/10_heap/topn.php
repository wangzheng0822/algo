<?php
/**
 * Created by PhpStorm.
 * User: 764432054@qq.com

 *动态数据集合求top n
 */
namespace Algo_10;

require_once '../vendor/autoload.php';

$static_data=[2,5,3,1,0,7,6,10];


//第3大
/*
2,5,3               2
2,5,3 1             2
2,5,3,1,0           2
2,5,3,1,0,7         3
2,5,3,1,0,7,6       5
2,5,3,1,0,7,6,10    6

维持1个小顶堆 大小为3即可
*/
$heap=new Heap(3);
foreach ($static_data as $v){
    echo "现在的第3大=>".$heap->topn($v).PHP_EOL;
}
