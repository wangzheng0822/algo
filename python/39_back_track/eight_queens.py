#!/usr/bin/python
# -*- coding: UTF-8 -*-

# 棋盘尺寸
BOARD_SIZE = 8

solution_count = 0
queen_list = [0] * BOARD_SIZE


def eight_queens(cur_column: int):
    """
    输出所有符合要求的八皇后序列
    用一个长度为8的数组代表棋盘的列，数组的数字则为当前列上皇后所在的行数
    :return:
    """
    if cur_column >= BOARD_SIZE:
        global solution_count
        solution_count += 1
        # 解
        print(queen_list)
    else:
        for i in range(BOARD_SIZE):
            if is_valid_pos(cur_column, i):
                queen_list[cur_column] = i
                eight_queens(cur_column + 1)


def is_valid_pos(cur_column: int, pos: int) -> bool:
    """
    因为采取的是每列放置1个皇后的做法
    所以检查的时候不必检查列的合法性，只需要检查行和对角
    1. 行：检查数组在下标为cur_column之前的元素是否已存在pos
    2. 对角：检查数组在下标为cur_column之前的元素，其行的间距pos - QUEEN_LIST[i]
       和列的间距cur_column - i是否一致
    :param cur_column:
    :param pos:
    :return:
    """
    i = 0
    while i < cur_column:
        # 同行
        if queen_list[i] == pos:
            return False
        # 对角线
        if cur_column - i == abs(pos - queen_list[i]):
            return False
        i += 1
    return True


if __name__ == '__main__':
    print('--- eight queens sequence ---')
    eight_queens(0)

    print('\n--- solution count ---')
    print(solution_count)
