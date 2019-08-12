#[derive(Debug)]
struct Heap {
    data: Vec<Option<i32>>,
    capacity: usize,
    count: i32,
}

impl Heap {
    pub fn new(capacity: usize) -> Self {
        Heap {
            data: vec![None; capacity],
            capacity: capacity,
            count: 0
        }
    }

    pub fn insert(&mut self, x: i32) -> bool {
        // 堆已满
        if self.capacity as i32 == self.count { return false; }

        self.data[self.count as usize] = Some(x);
        if self.count == 0 {
            self.count += 1;
            return true;
        }

        let mut idx = self.count as usize;
        // 子节点大于父节点，子节点与父节点交换
        // 自底向上堆化
        let mut parent_idx = ((idx - 1) >> 1) as usize;
        while parent_idx > 0 && self.data[idx] > self.data[parent_idx] {
            self.swap(idx, parent_idx);
            idx = parent_idx;
            parent_idx = ((idx - 1) >> 1) as usize;
        }
        self.count += 1;
        true
    }

    pub fn remove_max(&mut self) -> Option<i32> {
        // 堆已空
        if self.count == 0 { return None; }

        let max_value = self.data[0];
        // 将最后一个叶子节点移至堆顶
        self.data[0] = self.data[(self.count - 1) as usize];
        self.data[(self.count - 1) as usize] = None;

        self.heapify();
        self.count -= 1;
        max_value
    }

    // 堆化，自上向下堆化
    fn heapify(&mut self) {
        let mut idx = 0usize;
        loop {
            let mut max_pos = idx;
            if (2 * idx + 1) as i32 <= self.count && self.data[idx] < self.data[2 * idx + 1] { max_pos = 2 * idx + 1; }
            if (2 * idx + 2) as i32 <= self.count && self.data[max_pos] < self.data[2 * idx + 2] { max_pos = 2 * idx + 2; }

            if max_pos == idx { break; }
            self.swap(idx, max_pos);
            idx = max_pos;
        }
    }

    fn swap(&mut self, idx: usize, parent_idx: usize) {
        let tmp = self.data[parent_idx];
        self.data[parent_idx] = self.data[idx];
        self.data[idx] = tmp;
    }
}

fn main() {
    let mut h = Heap::new(16);
    h.insert(33);
    h.insert(27);
    h.insert(21);
    h.insert(16);
    h.insert(13);
    h.insert(15);
    h.insert(9);
    h.insert(5);
    h.insert(6);
    h.insert(7);
    h.insert(8);
    h.insert(1);
    h.insert(2);
    h.insert(22);
    println!("{:?}", h);
    h.remove_max();
    println!("{:?}", h);
    h.remove_max();
    println!("{:?}", h);
    h.remove_max();
    println!("{:?}", h);
}
