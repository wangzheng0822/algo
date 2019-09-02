// https://leetcode.com/problems/search-in-a-binary-search-tree/
use super::util::tree::{TreeNode, to_tree};

// Iterating method
pub fn search_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
    let mut r = root.clone();
    while let Some(node) = r {
        if node.borrow().val == val { return Some(node); }
        if node.borrow().val > val {
            r = node.borrow().left.clone();
        } else {
            r = node.borrow().right.clone();
        }
    }
    None
}

// Recursive Approach
pub fn search_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
    if let Some(n) = &root {
        if n.borrow().val > val { return Self::search_bst(n.borrow().left.clone(), val); }
        if n.borrow().val < val { return Self::search_bst(n.borrow().right.clone(), val); }
    }
    root
}
