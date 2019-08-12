fn sort_string(s: String) -> Vec<Vec<char>> {
    let mut bucket: Vec<Vec<char>> = vec![vec![]; 3];
    for ch in s.as_bytes() {
        if ch as u8 >= 48 && ch as u8 <= 57 {
            bucket[0].push(ch);
        } else if ch as u8  >= 65 && ch as u8 <= 90 {
            bucket[1].push(ch);
        } else {
            bucket[2].push(ch);
        }
    }

    bucket
}
fn main() {
    let s = "DaFBCA789".to_string();
    println!("{:?}", sort_string(s));
}
