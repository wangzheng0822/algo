use super::util::linked_list::{ListNode, to_list};

pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut prev = None;
    let mut curr = head;

    while let Some(mut boxed_node) = curr.take() {
        let next = boxed_node.next.take();
        boxed_node.next = prev.take();

        prev = Some(boxed_node);
        curr = next;
    }

    prev
}

fn main() {
    println!("{:?}", reverse_list(to_list(vec![1, 2, 3, 4, 5])));
}
