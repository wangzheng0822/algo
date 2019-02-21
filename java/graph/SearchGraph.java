package graph;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by dell on 2019/2/21.
 *
 visited是用来记录已经被访问的顶点，用来避免顶点被重复访问。如果顶点 q 被访问，那
 相应的 visited[q] 会被设置为 true。
 queue是一个队列，用来存储已经被访问、但相连的顶点还没有被访问的顶点。因为广度
 优先搜索是逐层访问的，也就是说，我们只有把第 k 层的顶点都访问完成之后，才能访问
 第 k+1 层的顶点。当我们访问到第 k 层的顶点的时候，我们需要把第 k 层的顶点记录下
 来，稍后才能通过第 k 层的顶点来找第 k+1 层的顶点。所以，我们用这个队列来实现记录
 的功能。
 prev用来记录搜索路径。当我们从顶点 s 开始，广度优先搜索到顶点 t 后，prev 数组中存
 储的就是搜索的路径。不过，这个路径是反向存储的。prev[w] 存储的是，顶点 w 是从哪
 个前驱顶点遍历过来的。比如，我们通过顶点 2 的邻接表访问到顶点 3，那 prev[3] 就等于
 2。为了正向打印出路径，我们需要递归地来打印，你可以看下 print() 函数的实现方式。
 */
public class SearchGraph {

    private int v; // 顶点的个数
    private LinkedList<Integer> adj[]; // 邻接表
    public SearchGraph(int v) {
        this.v = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i) {
            adj[i] = new LinkedList<>();
        }
    }
    public void addEdge(int s, int t) { // 无向图一条边存两次
        adj[s].add(t);
        adj[t].add(s);
    }

    public static void main(String[] args) {
        SearchGraph searchGraph = new SearchGraph(8);
        searchGraph.addEdge(0,1);
        searchGraph.addEdge(0,3);
        searchGraph.addEdge(1,2);
        searchGraph.addEdge(1,4);
        searchGraph.addEdge(2,5);
        searchGraph.addEdge(3,4);
        searchGraph.addEdge(4,5);
        searchGraph.addEdge(4,6);
        searchGraph.addEdge(5,7);
        searchGraph.addEdge(6,7);

        //求最短路径
//        searchGraph.bfs(0,7);
        searchGraph.dfs(0,7);
    }


    /**广度优先遍历*/
    public void bfs(int s, int t) {
        if (s == t) return;
        boolean[] visited = new boolean[v];
        visited[s] = true;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);
        int[] prev = new int[v];
        for (int i = 0; i < v; ++i) {
            prev[i] = -1;
        }
        while (queue.size() != 0) {
            int w = queue.poll();
            for (int i = 0; i < adj[w].size(); ++i) {
                int q = adj[w].get(i);
                if (!visited[q]) {
                    prev[q] = w;
                    if (q == t) {
                        print(prev, s, t);
                        return;
                    }
                    visited[q] = true;
                    queue.add(q);
                }
            }
        }
    }

    private void print(int[] prev, int s, int t) { // 递归打印 s->t 的路径
        if (prev[t] != -1 && t != s) {
            print(prev, s, prev[t]);
        }
        System.out.print(t + " ");
    }


    /**深度优先遍历*/
    boolean found = false; // 全局变量或者类成员变量

    public void dfs(int s, int t) {
        found = false;
        boolean[] visited = new boolean[v];
        int[] prev = new int[v];
        for (int i = 0; i < v; ++i) {
            prev[i] = -1;
        }
        recurDfs(s, t, visited, prev);
        print(prev, s, t);
    }

    private void recurDfs(int w, int t, boolean[] visited, int[] prev) {
        if (found == true) return;
        visited[w] = true;
        if (w == t) {
            found = true;
            return;
        }
        for (int i = 0; i < adj[w].size(); ++i) {
            int q = adj[w].get(i);
            if (!visited[q]) {
                prev[q] = w;
                recurDfs(q, t, visited, prev);
            }
        }
    }


}
