struct NewArray {
    array: Vec<i32>,
    count: i32,
}

impl NewArray {
    fn new(capacity: usize) -> NewArray {
        NewArray { array: Vec::with_capacity(capacity), count: 0 }
    }

    fn find(&self, index: usize) -> i32 {
        if index > self.count as usize { return -1; }
        self.array[index]
    }

    fn insert(&mut self, index: usize, value: i32) -> bool {
        let array_count = self.count as usize;
        if index > array_count || array_count == self.array.capacity() { return false; }

        if index == array_count {
            self.array.push(value);
        } else {
            let tmp_arr = self.array.clone();

            self.array = Vec::with_capacity(self.array.capacity());
            for i in 0..index {
                self.array.push(tmp_arr[i]);
            }

            self.array.push(value);
            for i in index..array_count {
                self.array.push(tmp_arr[i]);
            }
        }

        self.count += 1;
        true
    }

    fn remove(&mut self, index: usize) -> i32 {
        if index >= self.count as usize { return -1; }

        let result = self.array[index];
        let tmp_arr = self.array.clone();

        self.array = Vec::with_capacity(self.array.capacity());
        for i in 0..index {
            self.array.push(tmp_arr[i]);
        }

        for i in index+1..self.count as usize {
            self.array.push(tmp_arr[i]);
        }

        self.count -=1;
        result
    }
}

fn main() {
    let mut new_array = NewArray::new(10);
    assert_eq!(new_array.insert(0, 3), true);
    assert_eq!(new_array.insert(1, 2), true);
    assert_eq!(new_array.insert(2, 8), true);
    assert_eq!(new_array.insert(0, 9), true);
    assert_eq!(new_array.insert(5, 7), false);
    assert_eq!(new_array.insert(4, 5), true);
    assert_eq!(new_array.find(3), 8);
    assert_eq!(new_array.find(12), -1);
    assert_eq!(new_array.remove(1), 3);
    assert_eq!(new_array.remove(9), -1);
}
