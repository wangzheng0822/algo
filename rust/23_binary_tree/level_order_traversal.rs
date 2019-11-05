// leetcode https://leetcode.com/problems/binary-tree-level-order-traversal/

use super::util::tree::{TreeNode, to_tree};
use std::collections::VecDeque;

pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
    let mut result: Vec<Vec<i32>> = vec![];
    if root.is_none() { return result; }

    let mut deque: VecDeque<Option<Rc<RefCell<TreeNode>>>> = VecDeque::new();
    deque.push_back(root);

    while !deque.is_empty() {
        let mut current_level = vec![];
        let mut added = false;
        let level_size = deque.len();

        for i in 0..level_size {
            let n = deque.pop_front();
            if let Some(Some(node)) = n {
                current_level.push(node.borrow().val);
                added = true;
                if node.borrow().left.is_some() { deque.push_back(node.borrow().left.clone()); }
                if node.borrow().right.is_some() { deque.push_back(node.borrow().right.clone()); }
            }
        }

        if !added { break; }

        result.push(current_level);
    }

    result
}
