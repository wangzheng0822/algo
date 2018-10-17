<?php

class LoopQueue
{   
    private $MaxSzie;
    private $data = [];
    private $head = 0;
    private $tail = 0;

    /**
     * 初始化队列大小 最后的位置不存放数据,实际大小 = size++
     */
    public function __construct($size = 10)
    {
        $this->MaxSzie = ++$size;
    }

    /**
     * 队列满条件  ($this->tail+1) % $this->MaxSzie == $this->head
     */
    public function enQueue($data)
    {
        if (($this->tail+1) % $this->MaxSzie == $this->head)
            return -1;

        $this->data[$this->tail] = $data;
        $this->tail = (++$this->tail) % $this->MaxSzie;
    }

    public function deQueue()
    {
        if ($this->head == $this->tail)
            return NULL;
        
        $data = $this->data[$this->head];
        unset($this->data[$this->head]);
        $this->head = (++$this->head) % $this->MaxSzie;
        return $data;
    }

    public function getLength()
    {
        return ($this->tail - $this->head + $this->MaxSzie) % $this->MaxSzie;
    }
}

$queue = new LoopQueue(4);
// var_dump($queue);
$queue->enQueue(1);
$queue->enQueue(2);
$queue->enQueue(3);
$queue->enQueue(4);
// $queue->enQueue(5);
var_dump($queue->getLength());
$queue->deQueue();
$queue->deQueue();
$queue->deQueue();
$queue->deQueue();
$queue->deQueue();
var_dump($queue);
