<?php

function quickSort(array &$a)
{
    $n = count($a);

    quickSortInternally($a, 0, $n-1);
}

function quickSortInternally(array &$a, int $l, int $r)
{
    if ($l >= $r) return;

    $q = partition($a, $l, $r);
    quickSortInternally($a, $l, $q-1);
    quickSortInternally($a, $q+1, $r);
}

function partition(&$a, $l, $r): int
{
    $pivot = $a[$r];
    $i = $l;

    for ($j = $l; $j < $r; ++$j) {
        if ($a[$j] < $pivot) {
            [$a[$j], $a[$i]] = [$a[$i], $a[$j]];
            ++$i;
      }
    }

    [$a[$r], $a[$i]] = [$a[$i], $a[$r]];

    return $i;
}

$a1 = [1,4,6,2,3,5,4];
$a2 = [2, 2, 2, 2];
$a3 = [4, 3, 2, 1];
$a4 = [5, -1, 9, 3, 7, 8, 3, -2, 9];
quickSort($a1);
print_r($a1);
quickSort($a2);
print_r($a2);
quickSort($a3);
print_r($a3);
quickSort($a4);
print_r($a4);