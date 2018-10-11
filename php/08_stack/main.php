<?php
/**
 * User: lide01
 * Date: 2018/10/11 20:01
 * Desc:
 */

namespace Algo_08;

require_once '../vendor/autoload.php';

$stack = new StackOnLinkedList();
$stack->pushData(1);
$stack->pushData(2);
$stack->pushData(3);
$stack->pushData(4);
var_dump($stack->getLength());
$stack->printSelf();

$topNode = $stack->top();
var_dump($topNode->data);

$stack->pop();
$stack->printSelf();
$stack->pop();
$stack->printSelf();

var_dump($stack->getLength());

$stack->pop();
$stack->pop();
$stack->printSelf();