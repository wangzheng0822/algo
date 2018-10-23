<?php

function insertSort(&$arr)
{
    $i = 0;
    $len = count($arr);

    while($i < $len){
        $data = $arr[$i+1];
        for ($j = $i;$j >=0 ;$j-- ){
            if ($data >= $arr[$j]){
                array_splice($arr, $i+1, 1);
                array_splice($arr, ++$j, 0, $data);
                break;
            }
        }
        
        $i++;
    }
}

$arr = [1,4,6,2,3,5,4];
insertSort($arr);
var_dump($arr);