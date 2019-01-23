package tree24;

public class BinaryTree {

    public static void main(String[] args) {

        BinaryTreeNode root = new BinaryTreeNode(1, new BinaryTreeNode(2, new BinaryTreeNode(4), new BinaryTreeNode(5)),
                new BinaryTreeNode(3, new BinaryTreeNode(6), new BinaryTreeNode(7)));
        System.out.println(
                "----------1-------\n" +
                "----2--------3----\n" +
                        "-4-----5- -6------7--");
        preOrder(root);
        System.out.println("--------------------");
        inOrder(root);
        System.out.println("--------------------");
        postOrder(root);
    }


    static void preOrder(BinaryTreeNode root) {
        if (root == null) return;
        System.out.println(root.data);
        preOrder(root.left);
        preOrder(root.right);
    }

    static void inOrder(BinaryTreeNode root) {
        if (root == null) return;
        inOrder(root.left);
        System.out.println(root.data);
        inOrder(root.right);
    }

    static void postOrder(BinaryTreeNode root) {
        if (root == null) return;
        postOrder(root.left);
        postOrder(root.right);
        System.out.println(root.data);
    }

    //二叉树节点
    static class BinaryTreeNode {
        private int data;
        private BinaryTreeNode left;
        private BinaryTreeNode right;

        public BinaryTreeNode() {}

        public BinaryTreeNode(int data, BinaryTreeNode left, BinaryTreeNode right) {
            super();
            this.data = data;
            this.left = left;
            this.right = right;
        }

        public BinaryTreeNode(int data) {
            super();
            this.data = data;
        }

        public int getData() {
            return data;
        }

        public void setData(int data) {
            this.data = data;
        }

        public BinaryTreeNode getLeft() {
            return left;
        }

        public void setLeft(BinaryTreeNode left) {
            this.left = left;
        }

        public BinaryTreeNode getRight() {
            return right;
        }

        public void setRight(BinaryTreeNode right) {
            this.right = right;
        }
    }
}
