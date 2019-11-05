fn regex_match(text: &str, regex: &str) -> bool {
    let mut matched = false;
    let text_chars = text.chars().collect();
    let regex_chars = regex.chars().collect();
    rematch(&text_chars, &regex_chars, 0, 0, &mut matched);
    matched
}

fn rematch(text_chars:  &Vec<char>,
           regex_chars: &Vec<char>,
           t_idx:       usize,
           r_idx:       usize,
           matched:     &mut bool) {
    // 已经匹配好了，直接返回；
    if *matched { return; }

    // 正则串已经全部匹配
    if r_idx >= regex_chars.len() {
        *matched = true;
        return;
    }

    // 主串已经匹配完，但是正则串还没有全部进行匹配
    if t_idx >= text_chars.len() && r_idx < regex_chars.len() {
        *matched = false;
        return;
    }

    // * 匹配1个或多个字符，递归进行匹配
    if regex_chars[r_idx] == '*' {
        for i in t_idx..text_chars.len() {
            rematch(text_chars, regex_chars, i+1, t_idx+1, matched);
        }
    // ? 匹配0个或1个字符，分两种情况进行匹配
    } else if regex_chars[r_idx] == '?' {
        rematch(text_chars, regex_chars, t_idx+1, r_idx+1, matched);
        rematch(text_chars, regex_chars, t_idx, r_idx+1, matched);
    // 非特殊字符，精确匹配
    } else if regex_chars[r_idx] == text_chars[t_idx] {
        rematch(text_chars, regex_chars, t_idx+1, r_idx+1, matched);
    }
}

fn main() {
    let text = "abcdsadfkjlekjoiwjiojieeecd";
    let regex = "ab*eee?d";
    let m = regex_match(text, regex);
    println!("{}", m);
}
