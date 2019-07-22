// leetcode: https://leetcode.com/problems/binary-tree-inorder-traversal/
use super::util::tree::{TreeNode, to_tree};

// 中序遍历（Recursive Approach）
pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result: Vec<i32> = vec![];
    if root.is_none() { return result; }

    _inorder(root, &mut result);
    result
}

fn _inorder(root: Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
    match root {
        Some(node) => {
            _inorder(node.borrow().left.clone(), result);
            result.push(node.borrow().val);
            _inorder(node.borrow().right.clone(), result);
        },
        None => { return; }
    }
}

// 中序遍历（Iterating method using Stack）
pub fn inorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result = vec![];
    if root.is_none() { return result; }

    let mut stack: Vec<Rc<RefCell<TreeNode>>> = Vec::new();
    let mut r = root.clone();

    while r.is_some() || !stack.is_empty() {
        while let Some(node) = r {
            stack.push(node.clone());
            r = node.borrow().left.clone();
        }
        r = stack.pop();
        if let Some(node) = r {
            result.push(node.borrow().val);
            r = node.borrow().right.clone();
        }
    }
    result
}
