#[derive(Debug,Default)]
pub struct MyHashTable<'a> {
    table: Vec<Option<&'a str>>,
    capacity: usize,
}

impl<'a> MyHashTable<'a> {
    fn new() -> MyHashTable<'a> {
        MyHashTable {
            table: vec![None; 16],
            capacity: 16,
        }
    }

    pub fn insert(&mut self, key: &'a str, value: &'a str) {
        let pos = self.hash(key) as usize;
        self.table[pos] = Some(value);
    }

    pub fn get(&self, key: &'a str) -> Option<&'a str> {
        let pos = self.hash(key) as usize;
        self.table[pos]
    }

    pub fn remove(&mut self, key: &'a str) -> Option<&'a str> {
        let pos = self.hash(key) as usize;
        let value = self.table[pos];
        self.table[pos] = None;
        value
    }

    fn hash(&self, key: &'a str) -> i32 {
        let h = self.hash_code(key);
        (h ^ (h >> 16)) & (self.capacity as i32 - 1)
    }

    fn hash_code(&self, key: &'a str) -> i32 {
        let mut hash = 0;
        for ch in key.chars() {
            hash += 31 * hash + ch as i32;
        }
        hash as i32
    }
}
fn main() {
    let mut hash_table = MyHashTable::new();
    hash_table.insert("hello", "rust");
    println!("{:?}", hash_table);
    hash_table.insert("hi", "C++");
    println!("{:?}", hash_table);
    let m = hash_table.get("hello");
    println!("{:?}", m);
    let n = hash_table.remove("hi");
    println!("{:?}", n);
    println!("{:?}", hash_table);
}
