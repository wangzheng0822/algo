<?php

/**
 * 8皇后解法，共92种解法 回溯思想
 * Class Queen
 */
class Queen
{
    public $result = [];

    function cal8queens($row)
    {
        if ($row == 8) {
            $this->printQueens();
            return;
        }

        //每一行有8中放法
        for($column = 0; $column < 8; $column++) {
            if ($this->isOk($row, $column)) {
                $this->result[$row] = $column;
                $this->cal8queens($row + 1);
            }
        }
    }

    //row行的column列是否合适
    function isOk($row, $column)
    {
        $leftup = $column - 1;
        $rightdown = $column + 1;

        for ($i = $row - 1; $i >= 0; $i--) {
            //判断上一行的 column 列是否有值
            if ($this->result[$i] == $column) {
                return false;
            }

            //左上角是否有值
            if ($leftup >= 0 && $this->result[$i] == $leftup) {
                return false;
            }

            //右下角是否有值
            if ($rightdown < 8 && $this->result[$i] == $rightdown) {
                return false;
            }

            $leftup--;
            $rightdown++;

        }

        return true;
    }

    //打印
    function printQueens()
    {
        for ($row = 0; $row < 8; $row++) {
            for ($column = 0; $column < 8; $column++) {
                if ($this->result[$row] == $column) {
                    echo 'Q';
                } else {
                    echo '*';
                }
            }
            echo '<br>';
        }
    }
}

$queen = new Queen();
$queen->cal8queens(0);
