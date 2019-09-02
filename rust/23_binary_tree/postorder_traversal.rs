// https://leetcode.com/problems/binary-tree-postorder-traversal/
use super::util::tree::{TreeNode, to_tree};

// 后续遍历（Recursive Approach）
pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result: Vec<i32> = vec![];
    if root.is_none() { return result; }

    _postorder(root, &mut result);
    result
}

fn _postorder(root: Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
    match root {
        Some(node) => {
            _postorder(node.borrow().left.clone(), result);
            _postorder(node.borrow().right.clone(), result);
            result.push(node.borrow().val);
        },
        None => { return; }
    }
}

// 后序遍历（Iterating method using Stack）
pub fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result = vec![];
    if root.is_none() { return result; }

    let mut stack1: Vec<Option<Rc<RefCell<TreeNode>>>> = Vec::new();
    let mut stack2: Vec<Option<Rc<RefCell<TreeNode>>>> = Vec::new();
    stack1.push(root);

    while let Some(Some(node)) = stack1.pop() {
        if node.borrow().left.is_some() {
            stack1.push(node.borrow().left.clone());
        }
        if node.borrow().right.is_some() {
            stack1.push(node.borrow().right.clone());
        }
        stack2.push(Some(node));
    }

    while let Some(Some(node)) = stack2.pop() {
        result.push(node.borrow().val);
    }

    result
}
