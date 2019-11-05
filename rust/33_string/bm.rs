// 生成模式串散列表
fn generate_bc(pattern: &str) -> Vec<i32> {
    let mut bc: Vec<i32> = vec![-1; 256];
    let pattern_chars: Vec<char> = pattern.chars().collect();
    for (index, item) in pattern_chars.iter().enumerate() {
        bc[(*item as u8) as usize] = index as i32;
    }
    bc
}

// 计算 suffix 数组与 prefix 数组
fn generate_gs(pattern: &str) -> (Vec<i32>, Vec<bool>) {
    let m = pattern.len();
    let mut suffix: Vec<i32> = vec![-1; m];
    let mut prefix: Vec<bool> = vec![false; m];
    let pattern_chars: Vec<char> = pattern.chars().collect();

    for i in 0..m-1 {
        let mut j = i as i32;
        let mut k = 0;

        while j >= 0 && pattern_chars[j as usize] == pattern_chars[m-k-1] {
            j -= 1;
            k += 1;
            suffix[k] = j + 1;
        }

        if j == -1 { prefix[k] = true; }
    }

    (suffix, prefix)
}

fn move_by_gs(bad_char_start_index: usize, pattern_len: usize, suffix: &Vec<i32>, prefix: &Vec<bool>) -> i32 {
    // 好后缀长度
    let k = pattern_len - bad_char_start_index - 1;
    // 完全匹配
    if suffix[k] != -1 { return (bad_char_start_index + 1 - suffix[k] as usize) as i32; }

    for i in pattern_len+2..bad_char_start_index {
        if prefix[pattern_len-i] { return i as i32; }
    }
    // 没有匹配
    pattern_len as i32
}

fn bm_search(primary: &str, pattern: &str) -> i32 {
    if primary.is_empty() || pattern.is_empty() || pattern.len() > primary.len() { return 0; }

    let primary_chars: Vec<char> = primary.chars().collect();
    let pattern_chars: Vec<char> = pattern.chars().collect();
    let bc = generate_bc(pattern);
    let (suffix, prefix) = generate_gs(pattern);
    let n = primary.len();
    let m = pattern.len();
    let mut i = 0;

    while i <= n - m {
        let mut j = (m-1) as i32;
        while j >=0 {
            if primary_chars[i+j as usize] != pattern_chars[j as usize] { break; }
            j -= 1
        }
        if j < 0 { return i as i32; }
        let step_for_bc = j as i32 - bc[(primary_chars[i+j as usize] as u8) as usize];
        let mut step_for_gs = 0;
        if j < (m-1) as i32 {
            step_for_gs = move_by_gs(j as usize, m, &suffix, &prefix);
        }
        i = (i as i32 + step_for_bc.max(step_for_gs)) as usize;
    }
    -1
}

fn main() {
    let primary = "abcacabcbcabcabc";
    let pattern = "cabcab";
    let m = bm_search(primary, pattern);
    println!("{:?}", m);
}
