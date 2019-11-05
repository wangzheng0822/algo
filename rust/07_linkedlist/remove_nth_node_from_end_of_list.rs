use super::util::linked_list::{ListNode, to_list};

pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
    let mut dummy = Some(Box::new(ListNode { val: 0, next: head }));
    let mut cur = &mut dummy;
    let mut length = 0;

    while let Some(_node) = cur.as_mut() {
        cur = &mut cur.as_mut().unwrap().next;
        if let Some(_inner_node) = cur { length += 1; }
    }

    let mut new_cur = dummy.as_mut();
    let idx = length - n;

    for _ in 0..idx {
        new_cur = new_cur.unwrap().next.as_mut();
    }

    let next = new_cur.as_mut().unwrap().next.as_mut().unwrap().next.take();
    new_cur.as_mut().unwrap().next = next;

    dummy.unwrap().next
}

fn main() {
    println!("{:?}", remove_nth_from_end(to_list(vec![1, 3, 4])));
}
