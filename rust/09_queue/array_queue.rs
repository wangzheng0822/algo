#[derive(Debug)]
struct ArrayQueue {
    queue: Vec<i32>,
    head: i32,
    tail: i32,
}

impl ArrayQueue {
    fn new(n: usize) -> Self {
        ArrayQueue {
            queue: Vec::with_capacity(n),
            head: 0,
            tail: 0,
        }
    }

    fn enqueue(&mut self, num: i32) -> bool {
        let c = self.queue.capacity() as i32;
        // queue is full
        if self.head == 0 && self.tail == c { return false; }
        if self.tail == c {
            for i in 0..(self.tail-self.head) as usize {
                self.queue[i] = self.queue[self.head as usize + i];
            }
            self.tail -= self.head;
            self.head = 0;
            self.queue[self.tail as usize] = num;
        } else {
            self.queue.push(num);
        }

        self.tail += 1;
        true
    }

    fn dequeue(&mut self) -> i32 {
        if self.head == self.tail { return -1; }

        let shift = self.queue[self.head as usize];
        self.head += 1;
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
    let mut queue = ArrayQueue::new(3);
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
