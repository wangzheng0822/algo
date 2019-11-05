<?php
/**
 * Created by PhpStorm.
 * User: 764432054@qq.com
 * Date: 2019/9/22
 * Time: 23:30
 *
 *二叉树的层级遍历
 */


namespace Algo_24;

require_once '../vendor/autoload.php';

$tree=new Tree(20);
$tree->insert(16);
$tree->insert(30);
$tree->insert(12);
$tree->insert(19);

$tree->insert(10);
$tree->insert(15);
$tree->insert(18);
$tree->insert(21);
$tree->insert(38);


$q=$tree->levelOrder([$tree->head]);

foreach ($q as $n){
    echo $n->data." ";
}
echo PHP_EOL;