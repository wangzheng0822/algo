"""
    Author: Wenru Dong
"""

def levenshtein_dp(s: str, t: str) -> int:
    m, n = len(s), len(t)
    table = [[0] * (n + 1) for _ in range(m + 1)]
    table[0] = [j for j in range(m + 1)]
    for i in range(m + 1):
        table[i][0] = i
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            table[i][j] = min(1 + table[i - 1][j], 1 + table[i][j - 1], int(s[i - 1] != t[j - 1]) + table[i - 1][j - 1])
    return table[-1][-1]


def common_substring_dp(s: str, t: str) -> int:
    m, n = len(s), len(t)
    table = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            table[i][j] = max(table[i - 1][j], table[i][j - 1], int(s[i - 1] == t[j - 1]) + table[i - 1][j - 1])
    return table[-1][-1]


if __name__ == "__main__":
    s = "mitcmu"
    t = "mtacnu"

    print(levenshtein_dp(s, t))
    print(common_substring_dp(s, t))