#[derive(Debug)]
struct CircleQueue {
    queue: Vec<i32>,
    head: i32,
    tail: i32,
    n: i32,
}

impl CircleQueue {
    fn new(n: i32) -> Self {
        CircleQueue {
            queue: vec![-1; n as usize],
            head: 0,
            tail: 0,
            n: n,
        }
    }

    fn enqueue(&mut self, num: i32) -> bool {
        if (self.tail + 1) % self.n == self.head { return false; }
        self.queue[self.tail as usize] = num;
        self.tail = (self.tail + 1) % self.n;
        true
    }

    fn dequeue(&mut self) -> i32 {
        if self.head == self.tail { return -1; }

        let shift = self.queue[self.head as usize];
        self.head = (self.head + 1) % self.n;
        shift
    }

    fn print_all(&self) {
        let mut s = String::from("");
        for i in self.head..self.tail {
            s.push(self.queue[i as usize] as u8 as char);
            s.push_str("->");
        }
        println!("{:?}", s);
    }
}

fn main() {
    let mut queue = CircleQueue::new(10);
    queue.enqueue(2);
    queue.enqueue(2);
    queue.enqueue(2);
    queue.enqueue(2);
    queue.dequeue();
    queue.dequeue();
    queue.enqueue(4);
    queue.dequeue();
    queue.print_all();
}
