#![feature(box_into_raw_non_null)]

use std::ptr::NonNull;

#[derive(Debug)]
pub struct LinkedListQueue {
    head: Option<NonNull<Node>>,
    tail: Option<NonNull<Node>>,
}

pub struct Node {
    next: Option<NonNull<Node>>,
    element: i32,
}

impl Node {
    fn new(element: i32) -> Self {
        Node {
            next: None,
            element,
        }
    }

    fn into_element(self: Box<Self>) -> i32 {
        self.element
    }
}

impl LinkedListQueue {
    pub fn new() -> Self {
        LinkedListQueue {
            head: None,
            tail: None,
        }
    }

    pub fn dequeue(&mut self) -> i32 {
        self.head.map(|node| unsafe {
            let node = Box::from_raw(node.as_ptr());
            self.head = node.next;
            node
        }).map(Node::into_element).unwrap()
    }

    pub fn enqueue(&mut self, elt: i32) {
        let mut node = Box::new(Node::new(elt));
        unsafe {
            node.next = None;
            let node = Some(Box::into_raw_non_null(node));

            match self.tail {
                None => self.head = node,
                Some(tail) => (*tail.as_ptr()).next = node,
            }

            self.tail = node;
        }
    }
}

fn main() {
    let mut m = LinkedListQueue::new();
    m.enqueue(4);
    m.enqueue(4);
    m.enqueue(4);
    m.dequeue();
    m.dequeue();
    println!("{:?}", m);
}
