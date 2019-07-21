use super::util::tree::{TreeNode, to_tree};

// 前序遍历
pub fn pre_order_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result: Vec<i32> = vec![];
    if root.is_none() { return result; }

    _pre_order(root, &mut result);
    result
}

fn _pre_order(root: Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
    match root {
        Some(node) => {
            result.push(node.borrow().val);
            _pre_order(node.borrow().left.clone(), result);
            _pre_order(node.borrow().right.clone(), result);
        },
        None => { return; }
    }
}

// 中序遍历
pub fn in_order_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result: Vec<i32> = vec![];
    if root.is_none() { return result; }

    _in_order(root, &mut result);
    result
}

fn _in_order(root: Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
    match root {
        Some(node) => {
            _in_order(node.borrow().left.clone(), result);
            result.push(node.borrow().val);
            _in_order(node.borrow().right.clone(), result);
        },
        None => { return; }
    }
}

// 后续遍历
pub fn post_order_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut result: Vec<i32> = vec![];
    if root.is_none() { return result; }

    _post_order(root, &mut result);
    result
}

fn _post_order(root: Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<i32>) {
    match root {
        Some(node) => {
            _post_order(node.borrow().left.clone(), result);
            _post_order(node.borrow().right.clone(), result);
            result.push(node.borrow().val);
        },
        None => { return; }
    }
}
