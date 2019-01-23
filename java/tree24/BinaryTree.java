package tree24;

public class BinaryTree {

    public static void main(String[] args) {

        Node root = new Node(1, new Node(2, new Node(4), new Node(5)),
                new Node(3, new Node(6), new Node(7)));
        System.out.println(
                "----------1-------\n" +
                "----2--------3----\n" +
                "-4-----5- -6------7--\n");

        preOrder(root);
        System.out.println("\n--------------------");
        inOrder(root);
        System.out.println("\n--------------------");
        postOrder(root);
    }


    static void preOrder(Node root) {
        if (root == null) return;
        System.out.print(root.data);
        preOrder(root.left);
        preOrder(root.right);
    }

    static void inOrder(Node root) {
        if (root == null) return;
        inOrder(root.left);
        System.out.print(root.data);
        inOrder(root.right);
    }

    static void postOrder(Node root) {
        if (root == null) return;
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data);
    }

    //二叉树节点
    static class Node {
        private int data;
        private Node left;
        private Node right;

        public Node() {}

        public Node(int data, Node left, Node right) {
            super();
            this.data = data;
            this.left = left;
            this.right = right;
        }

        public Node(int data) {
            super();
            this.data = data;
        }
    }
}
