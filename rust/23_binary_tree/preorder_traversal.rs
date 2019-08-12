//leetcode: https://leetcode.com/problems/binary-tree-preorder-traversal/
use super::util::tree::{TreeNode, to_tree};

// 前序遍历（Recursive Approach）
pub fn preorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result: Vec<i32> = vec![];
    if root.is_none() { return result; }

    _preorder(root, &mut result);
    result
}

fn _preorder(root: Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
    match root {
        Some(node) => {
            result.push(node.borrow().val);
            _preorder(node.borrow().left.clone(), result);
            _preorder(node.borrow().right.clone(), result);
        },
        None => { return; }
    }
}

// 前序遍历（Iterating method using Stack）
pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result = vec![];
    if root.is_none() { return result; }

    let mut stack: Vec<Rc<RefCell<TreeNode>>> = Vec::new();
    let mut r = root.clone();

    while r.is_some() || !stack.is_empty() {
        while let Some(node) = r {
            result.push(node.borrow().val);
            stack.push(node.clone());
            r = node.borrow().left.clone();
        }
        r = stack.pop();
        if let Some(node) = r {
            r = node.borrow().right.clone();
        }
    }
    result
}
