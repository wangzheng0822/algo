<?php
/**
 * User: Hkesd
 * Date: 2018/10/13 11:46
 * Desc:
 */

namespace Algo_09;

require_once "../vendor/autoload.php";

$queue = new QueueOnLinkedList();
$queue->enqueue(1);
$queue->enqueue(2);
$queue->enqueue(3);
$queue->enqueue(4);
$queue->enqueue(5);
$queue->printSelf();
var_dump($queue->getLength());

$queue->dequeue();
$queue->printSelf();
$queue->dequeue();
$queue->dequeue();
$queue->dequeue();
$queue->printSelf();

$queue->dequeue();
$queue->printSelf();
