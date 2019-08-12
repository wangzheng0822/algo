// https://leetcode.com/problems/maximum-depth-of-binary-tree/
use super::util::tree::{TreeNode, to_tree};

// max depth BFS
pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    if root.is_none() { return 0; }

    let mut depth = 0;
    let mut deque: VecDeque<Option<Rc<RefCell<TreeNode>>>> = VecDeque::new();
    deque.push_back(root);

    while !deque.is_empty() {
        let level_size = deque.len();
        let mut added = false;
        depth += 1;
        for _i in 0..level_size {
            added = true;
            if let Some(Some(node)) = deque.pop_front() {
                if node.borrow().left.is_some() { deque.push_back(node.borrow().left.clone());}
                if node.borrow().right.is_some() { deque.push_back(node.borrow().right.clone());}
            }
        }
        if !added { break; }
    }
    depth
}

// max depth DFS
pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    match root {
        Some(node) => {
            let left = Self::max_depth(node.borrow().left.clone());
            let right = Self::max_depth(node.borrow().right.clone());
            1 + left.max(right)
        },
        _ => 0,
    }
}
