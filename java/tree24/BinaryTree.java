package tree24;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

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
        System.out.println("\n--------------------");
        printFromTopToBottom(root);
    }

    /**
     * 层序遍历
     * @param root
     * @return
     */
    public static ArrayList<Integer> printFromTopToBottom(Node root) {
        ArrayList<Integer> list = new ArrayList<>();  //存放结果
        Queue<Node> queue = new LinkedList<>();   //辅助队列
        if (root != null) {
            //根节点入队
            queue.offer(root);
        }
        //队列不为空，执行循环
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            list.add(node.data);     //将队列元素输出

            //如果有左节点，就把左节点加入
            if (node.left != null) {
                queue.offer(node.left);
            }
            //如果有右节点，就把右节点加入
            if (node.right != null) {
                queue.offer(node.right);
            }
        }
        list.forEach(System.out::print);
        return list;
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

        public Node() {
        }

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
