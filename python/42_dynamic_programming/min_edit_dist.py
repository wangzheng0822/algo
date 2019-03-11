"""
    Author: Wenru Dong
"""

def levenshtein_dp(s: str, t: str) -> int:
    m, n = len(s), len(t)
    table = [[0] * (n) for _ in range(m)]

    for i in range(n):
        if s[0] == t[i]:
            table[0][i] = i - 0
        elif i != 0:
            table[0][i] = table[0][i - 1] + 1
        else:
            table[0][i] = 1

    for i in range(m):
        if s[i] == t[0]:
            table[i][0] = i - 0
        elif i != 0:
            table[i][0] = table[i - 1][0] + 1
        else:
            table[i][0] = 1

    for i in range(1, m):
        for j in range(1, n):
            table[i][j] = min(1 + table[i - 1][j], 1 + table[i][j - 1], int(s[i] != t[j]) + table[i - 1][j - 1])

    print(table)
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

    s = "kitten"
    t = "sitting"

    print(levenshtein_dp(s, t))
    print(common_substring_dp(s, t))

    s = "flaw"
    t = "lawn"

    print(levenshtein_dp(s, t))
    print(common_substring_dp(s, t))