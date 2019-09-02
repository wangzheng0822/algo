use std::collections::HashMap;

fn bf(primary: &str, pattern: &str) -> i32 {
    if primary.is_empty() || pattern.is_empty() || primary.len() < pattern.len() { return -1; }

    let primary_chars: Vec<char> = primary.chars().collect();
    let pattern_chars: Vec<char> = pattern.chars().collect();
    for i in 0..(primary.len() - pattern.len() + 1) {
        if pattern_chars == primary_chars[i..i + pattern.len()].to_vec() {
            return i as i32;
        }
    }
    -1
}

// 通过哈希算法对主串中的 n-m+1 个子串分别求哈希值，
// 逐个与模式串的哈希值比较大小。如果某个子串的哈希值与模式串相等，那就说明对应的子串和模式串匹配
fn rk(primary: &str, pattern: &str) -> i32 {
    if primary.is_empty() || pattern.is_empty() || primary.len() < pattern.len() { return -1; }

    let primary_chars: Vec<char> = primary.chars().collect();
    let pattern_chars: Vec<char> = pattern.chars().collect();
    let base: i128 = 26;
    let m = pattern.len();
    let n = primary.len();
    let mut pow_vec = vec![];
    let mut hash = HashMap::new();

    // 存储 26 的 n 次方到数组中，方便后面调用
    for i in 0..m {
        pow_vec.push(base.pow(i as u32));
    }

    // 计算子串的 hash 值
    let mut p_value = 0;
    for i in 0..m {
        p_value += (pattern_chars[i] as i128 - 'a' as i128) * pow_vec[m-1-i];
    }

    // 计算主串的 n-m+1 个子串的 hash 值
    for i in 0..(n - m + 1) {
        // 计算主串中 index 为 0 的子串的 hash 值
        let mut value = 0;
        if i == 0 {
            for i in 0..m {
                value += (primary_chars[i] as i128 - 'a' as i128) * pow_vec[m-1-i];
            }
        } else {
            // 计算 index 为 i 的子串的 hash 值
            // 计算公式: hash[i] = (hash[i-1] - 26^(m-1) * (primary_chars[i-1] - 'a')) * 26 + (26^0 * (primary_chars[i+m-1] - 'a'))
            value = (hash[&((i-1) as i32)] - base.pow((m-1) as u32) * (primary_chars[i-1] as i128 - 'a' as i128)) * base + ((primary_chars[i+m-1]) as i128 - 'a' as i128);
        }

        // hash 值相等，比较两个串内容是否相等，避免 hash 碰撞
        if value == p_value && pattern_chars == primary_chars[i..i+m].to_vec() {
            return i as i32;
        }

        hash.insert(i as i32, value);
    }

    -1
}

fn main() {
    let primary = "thequickbrownfoxjumpsoverthelazydog";
    let pattern = "jump";
    let result = bf(primary, pattern);
    println!("{}", result); // 16

    let result2 = rk(primary, pattern);
    println!("{:?}", result2); // 16
}
