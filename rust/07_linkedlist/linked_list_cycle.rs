use super::util::linked_list::{ListNode, to_list};

pub fn has_cycle(head: Option<Box<ListNode>>) -> bool {
    let mut fast_p = &head;
    let mut slow_p = &head;

    while fast_p.is_some() && fast_p.as_ref().unwrap().next.is_some() {
        slow_p = &slow_p.as_ref().unwrap().next;
        fast_p = &fast_p.as_ref().unwrap().next.as_ref().unwrap().next;

        if slow_p == fast_p { return true; }
    }
    false
}

fn main() {
    println!("{:?}", has_cycle(to_list(vec![1, 2, 3, 4, 5])));
}
