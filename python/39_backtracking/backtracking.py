"""
    Author: Wenru Dong
"""

from typing import List

def eight_queens() -> None:
    solutions = []

    def backtracking(queens_at_column: List[int], index_sums: List[int], index_diffs: List[int]) -> None:
        row = len(queens_at_column)
        if row == 8:
            solutions.append(queens_at_column)
            return
        for col in range(8):
            if col in queens_at_column or row + col in index_sums or row - col in index_diffs: continue
            backtracking(queens_at_column + [col], index_sums + [row + col], index_diffs + [row - col])
    
    backtracking([], [], [])
    print(*(" " + " ".join("*" * i + "Q" + "*" * (8 - i - 1) + "\n" for i in solution) for solution in solutions), sep="\n")


if __name__ == "__main__":

    eight_queens()
