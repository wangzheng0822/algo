// https://leetcode.com/problems/insert-into-a-binary-search-tree/
use super::util::tree::{TreeNode, to_tree};

pub fn insert_into_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
    insert(&root, val);
    root
}
fn insert(node: &Option<Rc<RefCell<TreeNode>>>, val: i32) {
    if let Some(n) = node {
        let mut n = n.borrow_mut();
        let target = if val > n.val { &mut n.right } else { &mut n.left };

        if target.is_some() {
            return insert(target, val);
        }

        *target = Some(Rc::new(RefCell::new(TreeNode::new(val))));
    }
}
