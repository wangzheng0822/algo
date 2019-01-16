package linkedlist07;

/**
 * Created by dell on 2019/1/16.
 */
public class LinkedListAlgoCode
{

    public static void main(String[] args) {
        Node node0 = new Node(5, null);
        Node node1 = new Node(4, node0);
        Node node2 = new Node(3, node1);
        Node node3 = new Node(2, node2);
        Node node4 = new Node(1, node3);


        Node node5 = new Node(9, null);
        Node node6 = new Node(8, node5);
        Node node7 = new Node(7, node6);
        Node node8 = new Node(4, node7);
        Node node9 = new Node(1, node8);
//        printAll(node4);

        //反转
//        printAll(reverse(node4));

        //求中间节点
//        System.out.println(mid(node4).data);

//        printAll(deleteLastK(node4, 3));

        printAll(mergeTwoSortedList(node9, node4));
    }

    /** 合并两个有序链表 */
    public static Node mergeTwoSortedList(Node la, Node lb){
        if(la == null) return lb;
        if(lb == null) return la;
        Node head = null;

        if(la.data <= lb.data){
            head = la;
            head.next = mergeTwoSortedList(la.next, lb);
        } else {
            head = lb;
            head.next = mergeTwoSortedList(la, lb.next);
        }
        return head;
    }

    /**删除倒数第k个节点*/
    public static Node deleteLastK(Node head, int k){
        Node fast = head;

        int i = 1;
        while (fast != null && i<k ){
            fast = fast.next;
            ++i;
        }
        if(fast == null){
            return head;
        }
        Node slow = head;
        Node prev = null;

        //终止条件：fast到最后一个节点
        while (fast.next != null){
            fast = fast.next;
            prev = slow;
            slow = slow.next;
        }
        if(prev == null){
            head = head.next;
        }else {
            prev.next = prev.next.next;
        }
        return head;
    }

    /**求中间节点*/
    public static Node mid(Node head){
        if(head == null){
            return head;
        }
        Node fast = head, slow = head;
        while (fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

    /**反转*/
    public static Node reverse(Node head){

        if(head == null || head.next == null){
            return head;
        }
        Node p,q,r;
        p = head;
        q = head.next;
        head.next = null;

        while (q != null){
            r = q.next;
            q.next = p;
            p = q;
            q = r;
        }
        head = p;
        return head;
    }



    public static void printAll(Node list) {
        Node p = list;
        while (p != null) {
            System.out.print(p.data + "-");
            p = p.next;
        }
        System.out.println();
    }

    public static class Node {
        private int data;
        private Node next;

        public Node(int data, Node next) {
            this.data = data;
            this.next = next;
        }

        public int getData() {
            return data;
        }
    }

}
