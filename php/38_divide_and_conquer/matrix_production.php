<?php

function popRow(&$matrix)
{
    return empty($matrix) ? [] : [array_shift($matrix)];
}

function popColumn(&$matrix)
{
    $column = [];

    foreach ($matrix as $key => &$row) {
        $data = array_shift($row);
        if (empty($data) || empty($row)) {
            unset($matrix[$key]);
        }
        $column[] = [$data];
    }
    return $column;
}

function countProduction($row, $column)
{
    for ($i = 0, $sum = 0; $i < count($row[0]); $i++) {
        $sum += $row[0][$i] * $column[$i][0];
    }
    return $sum;
}

function merger($value1, $value2, $value3, $value4)
{
    if (empty($value2) && empty($value3)) {
        return $value1;
    } else {
        $array12 = array_merge([$value1], !is_array($value2) ? [$value2] : $value2);
        if (!is_array($value3)) {
            $array34 = array_merge([$value3], !is_array($value4) ? [$value4] : $value4);
            return [$array12, $array34];
        } else {
            for ($i = 0, $array34 = []; $i < count($value3); $i++) {
                $array34[] = array_merge($value3[$i], $value4[$i]);
            }
            return array_merge([$array12], $array34);
        }
    }
}

function matrixProduction($matrix1, $matrix2)
{
    $row = popRow($matrix1);
    $column = popColumn($matrix2);

    if (empty($row) || empty($column)) {
        return [];
    }

    $value1 = countProduction($row, $column);
    $value2 = matrixProduction($row, $matrix2);
    $value3 = matrixProduction($matrix1, $column);
    $value4 = matrixProduction($matrix1, $matrix2);

    return merger($value1, $value2, $value3, $value4);
}

$matrix1 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
];

$matrix2 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
];

var_dump(matrixProduction($matrix1, $matrix2));
