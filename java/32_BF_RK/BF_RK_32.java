/**
 * 字符串匹配
 */
public class BF_RK_32 {

    /**
     * bf字符串串匹配
     *
     * @param main    主串
     * @param pattern 模式串
     * @return -1未匹配 或者 匹配下边起始值
     */
    public static int indexBf(char[] main, char[] pattern) {
        // 最大首个字符索引
        int maxFirst = main.length - pattern.length;
        char first = pattern[0];
        for (int i = 0; i <= maxFirst; i++) {
            // 第一个匹配的字符
            while (first != main[i]) {
                if (++i > maxFirst) return -1;
            }

            // 子串匹配
            int m = i + 1;
            for (int j = 1; j < pattern.length; j++, m++) {
                if (main[m] != pattern[j]) break;
            }

            // 匹配成功
            if (m - i == pattern.length) return i;
        }
        return -1;
    }

    /**
     * rk字符串匹配
     * 1、假设字符串由 a - z 组成
     * 2、不存在hash冲突
     *
     * @param main    主串
     * @param pattern 模式串
     * @return -1未匹配 或者 匹配下边起始值
     */
    public static int indexRk(char[] main, char[] pattern) {
        int mLen = main.length;
        int pLen = pattern.length;
        int pHash = hash(pattern, 0, pLen);
        for (int i = 0; i < mLen - pLen + 1; i++) {
            if (pHash == hash(main, i, pLen)) return i;
        }
        return -1;
    }

    /**
     * 使用[a-z] 对应的[0-25] 26进制计算hash值
     *
     * @param chars 字符数组
     * @param start 起始下标
     * @param len   长度
     * @return
     */
    private static int hash(char[] chars, int start, int len) {
        int hash = 0;
        int x = 0;
        for (int i = start; i < start + len; i++, x++) {
            hash += Math.pow(26, len - x - 1) * (chars[i] - 'a');
        }
        return hash;
    }


    /**
     * rk字符串匹配
     * 改良：
     * 1、可以为所有字符串
     * 2、解决存在hash冲突
     * 3、优化hash函数
     *
     * @param
     * @return
     */
    public static int indexRk2(char[] main, char[] pattern) {
        int mLen = main.length;
        int pLen = pattern.length;
        int pHash = hashPrime(pattern, 0, pLen);
        for (int i = 0; i < mLen - pLen + 1; i++) {
            if (pHash == hashPrime(main, i, pLen)) {
                int j = 0, k = i;
                while (main[k++] != pattern[j++] || j > pLen) break;

                return i;
            }
        }
        return -1;
    }

    /**
     * 0-255下所有的质数
     */
    private static char[] PRIME_NUMBERS = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
            101, 103, 107, 109, 113,
            127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
            179, 181, 191, 193, 197, 199, 211};

    /**
     * 使用0-255下所有的质数计算hash值
     *
     * @param chars 字符数组
     * @param start 起始下标
     * @param len   长度
     * @return
     */
    private static int hashPrime(char[] chars, int start, int len) {
        int hash = 0;
        int primeLen = PRIME_NUMBERS.length;
        for (int i = start; i < start + len; i++) {
            hash += PRIME_NUMBERS[Objects.hashCode(chars[i]) % primeLen];
        }
        return hash;
    }

}
