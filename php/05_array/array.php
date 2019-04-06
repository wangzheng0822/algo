<?php
/**
 * Created by PhpStorm.
 * User: leo
 * Date: 2018/10/5
 * Time: 9:13
 */

/**
 * 简单数组类
 */
class MyArray
{
    //数据
    private $data;
    //容量
    private $capacity;
    //长度
    private $length;

    /**
     * MyArray constructor.
     * @param $capacity
     */
    public function __construct($capacity)
    {
        $capacity = intval($capacity);
        if($capacity <= 0) {
            return null;
        }
        $this->data = array();
        $this->capacity = $capacity;
        $this->length = 0;
    }

    /**
     * 数组是否已满
     * @return bool
     */
    public function checkIfFull()
    {
        if($this->length == $this->capacity) {
            return true;
        }
        return false;
    }

    /**
     * 判断索引index是否超出数组范围
     * @param $index
     * @return bool
     */
    private function checkOutOfRange($index)
    {
        if($index >= $this->length) {
           return true;
        }
        return false;
    }

    /**
     * 在索引index位置插入值value，返回错误码，0为插入成功
     * @param $index
     * @param $value
     * @return int
     */
    public function insert($index, $value)
    {
        $index = intval($index);
        $value = intval($value);
        if ($index < 0) {
            return 1;
        }

        if ($this->checkIfFull()) {
            return 2;
        }

        for ($i = $this->length - 1; $i >= $index; $i--) {
            $this->data[$i + 1] = $this->data[$i];
        }

        $this->data[$index] = $value;
        $this->length++;
        return 0;
    }

    /**
     * 删除索引index上的值，并返回
     * @param $index
     * @return array
     */
    public function delete($index)
    {
        $value = 0;
        $index = intval($index);
        if ($index < 0) {
            $code = 1;
            return [$code, $value];
        }
        if ($this->checkOutOfRange($index)) {
            $code = 2;
            return [$code, $value];
        }

        $value = $this->data[$index];
        for ($i = $index; $i < $this->length - 1; $i++) {
            $this->data[$i] = $this->data[$i + 1];
        }
        $this->length--;
        return [0, $value];
    }

    /**
     * 查找索引index的值
     * @param $index
     * @return array
     */
    public function find($index)
    {
        $value = 0;
        $index = intval($index);
        if ($index < 0) {
            $code = 1;
            return [$code, $value];
        }
        if ($this->checkOutOfRange($index)) {
            $code = 2;
            return [$code, $value];
        }
        return [0, $this->data[$index]];
    }

    public function printData()
    {
        $format = "";
        for ($i = 0; $i < $this->length; $i++) {
            $format .= "|" . $this->data[$i];
        }
        print($format . "\n");
    }
}
