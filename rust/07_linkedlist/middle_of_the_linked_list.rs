use super::util::linked_list::{ListNode, to_list};

pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut fast_p = &head;
    let mut slow_p = &head;

    while fast_p.is_some() && fast_p.as_ref().unwrap().next.is_some() {
        slow_p = &slow_p.as_ref().unwrap().next;
        fast_p = &fast_p.as_ref().unwrap().next.as_ref().unwrap().next;
    }
    slow_p.clone()
}

fn main() {
    println!("{:?}", middle_node(to_list(vec![1, 3, 4])));
}
