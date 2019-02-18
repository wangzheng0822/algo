package tree24;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree {

    public static void main(String[] args) {

        TreeNode root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                new TreeNode(3, new TreeNode(6), new TreeNode(7)));
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
        System.out.println("\n最大深度---------");

        System.out.println(maxDepth(root));
        ;
    }

    /**
     * 层序遍历
     */
    public static ArrayList<Integer> printFromTopToBottom(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<>();  //存放结果
        Queue<TreeNode> queue = new LinkedList<>();   //辅助队列
        if (root != null) {
            //根节点入队
            queue.offer(root);
        }
        //队列不为空，执行循环
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
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

    /**
     * 翻转二叉树
     */
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode tmp = root.right;
        root.right = root.left;
        root.left = tmp;
        //翻转下一次层级，判断非空
        if (root.right != null) {
            invertTree(root.right);
        }
        //翻转下一次层级，判断非空
        if (root.left != null) {
            invertTree(root.left);
        }
        return root;
    }

    /**
     * 求最大深度
     */
    public static int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        } else {
            int left_height = maxDepth(root.left);
            int right_height = maxDepth(root.right);
            return Math.max(left_height, right_height) + 1;
        }
    }

    /**
     * 求二叉树最大宽度
     * 假设满二叉树表示成数组序列, 根节点所在的位置为1, 则任意位于i节点的左右子节点的index为2*i, 2*i+1
     * 用一个List保存每层的左端点, 易知二叉树有多少层List的元素就有多少个. 那么可以在dfs的过程中记录每个
     * 节点的index及其所在的层level, 如果level > List.size()说明当前节点就是新的一层的最左节点, 将其
     * 加入List中, 否则判断当前节点的index减去List中对应层的最左节点的index的宽度是否大于最大宽度并更新
     **/
    private int maxW = 0;

    public int widthOfBinaryTree(TreeNode root) {
        dfs(root, 1, 1, new ArrayList<Integer>());
        return maxW;
    }

    private void dfs(TreeNode r, int level, int index, ArrayList<Integer> left) {

        if (r == null) {
            return;
        }
        if (level > left.size()) {
            left.add(index);
        }
        maxW = Math.max(maxW, index - left.get(level - 1) + 1);

        dfs(r.left, level + 1, index * 2, left);
        dfs(r.right, level + 1, index * 2 + 1, left);
    }

    /**
     * 前序遍历
     */
    static void preOrder(TreeNode root) {
        if (root == null) return;
        System.out.print(root.data);
        preOrder(root.left);
        preOrder(root.right);
    }

    /**
     * 中序遍历
     */
    static void inOrder(TreeNode root) {
        if (root == null) return;
        inOrder(root.left);
        System.out.print(root.data);
        inOrder(root.right);
    }

    /**
     * 后序遍历
     */
    static void postOrder(TreeNode root) {
        if (root == null) return;
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data);
    }

    //二叉树节点
    static class TreeNode {
        private int data;
        private TreeNode left;
        private TreeNode right;

        public TreeNode() {
        }

        public TreeNode(int data, TreeNode left, TreeNode right) {
            super();
            this.data = data;
            this.left = left;
            this.right = right;
        }

        public TreeNode(int data) {
            super();
            this.data = data;
        }
    }
}
