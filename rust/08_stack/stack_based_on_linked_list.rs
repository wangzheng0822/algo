#[derive(Hash, Eq, PartialEq, Debug, Default, Clone)]
pub struct ListNode {
    val: String,
    next: Option<Box<ListNode>>,
}

#[derive(Hash, Eq, PartialEq, Debug, Default, Clone)]
pub struct LinkedListStack {
    node: Option<Box<ListNode>>,
}

impl ListNode {
    fn new(val: String) -> Self {
        ListNode { val: val, next: None }
    }
}

impl LinkedListStack {
    pub fn new() -> Self {
        Default::default()
    }

    pub fn push(&mut self, x: String) {
        let mut n = ListNode::new(x);
        n.next = self.node.clone();
        self.node = Some(Box::new(n));
    }

    pub fn pop(&mut self) -> String {
        if self.is_empty() { return "-1".to_string(); }

        let val = self.node.as_ref().unwrap().val.clone();
        self.node = self.node.as_mut().unwrap().next.take();
        val.to_string()
    }

    pub fn print_all(&mut self) {
        let mut list = String::from("");

        while let Some(n) = self.node.as_mut() {
            list.push_str(&(n.val).to_string());
            list.push_str("-->");
            self.node = n.next.take();
        }
        println!("{:?}", list);
    }

    pub fn clear(&mut self) {
        self.node = None;
    }

    pub fn is_empty(&self) -> bool {
        if self.node.is_none() { true } else { false }
    }
}
//
// fn main() {
//     let mut stack = LinkedListStack::new();
//     stack.push("https://www.baidu.com".to_string());
//     stack.push("https://www.google.com".to_string());
//     stack.pop();
//     stack.push("https://twitter.com".to_string());
//     stack.print_all();
// }
