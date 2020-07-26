/**
 * 第k大的数
 * @param {array} arr 
 * @param {number} k  
 */
function kthNum(arr, k) {
  const len = arr.length;
  if (k > len) {
    return -1;
  }
  let start = 0;
  let end = len - 1;
  let p = partition(arr, start, end);
  while (p + 1 !== k) {
    if (p + 1 > k) {
      end = p - 1
      p = partition(arr, start, p - 1);
    } else {
      start = p + 1
      p = partition(arr, p + 1, len - 1);
    }
  }
  return arr[p];
}

function partition(arr, start, end) {
  let i = start;
  let pivot = arr[end];
  for (let j = start; j < end; j++) {
    if (arr[j] < pivot) {
      swap(arr, i, j);
      i += 1;
    }
  }
  swap(arr, i, end);
  return i;
}

function swap(arr, i, j) {
  if (i === j) return;
  let tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}
