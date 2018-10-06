<?php
/**
 * Created by PhpStorm.
 * User: leo
 * Date: 2018/10/5
 * Time: 9:13
 */
require "./array.php";
$myArr1 = new MyArray(10);
for($i=0;$i<9;$i++) {
    $myArr1->insert($i, $i+1);
}
$myArr1->printData();

$code = $myArr1->insert(6, 999);
echo "insert at 6: code:{$code}\n";
$myArr1->printData();

list($code, $value) = $myArr1->delete(6);
echo "delete at 6: code:{$code}, value:{$value}\n";
$myArr1->printData();

$code = $myArr1->insert(11, 999);
echo "insert at 11: code:{$code}\n";
$myArr1->printData();

list($code, $value) = $myArr1->delete(0);
echo "delete at 0: code:{$code}, value:{$value}\n";
$myArr1->printData();

list($code, $value) = $myArr1->find(0);
echo "find at 0: code:{$code}, value:{$value}\n";