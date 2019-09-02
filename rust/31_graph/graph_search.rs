use std::collections::LinkedList;
use std::collections::VecDeque;

// 无向图
#[derive(Debug)]
struct Graph {
    v:   i32,
    linked_vec: Vec<LinkedList<i32>>, // 邻接表
}

impl Graph {
    fn new(v: i32) -> Self {
        Graph {
            v: v,
            linked_vec: vec![LinkedList::new(); v as usize],
        }
    }

    // 无向图的每条边存两次
    fn add_edge(&mut self, s: i32, t: i32) {
        self.linked_vec[s as usize].push_back(t);
        self.linked_vec[t as usize].push_back(s);
    }

    fn bfs(&self, s: i32, t: i32) {
        if s == t { return; }

        let mut prev    = vec![-1; self.v as usize];
        let mut visited = vec![false; self.v as usize];
        let mut queue   = VecDeque::new();

        visited[s as usize] = true;
        queue.push_back(s);

        while !queue.is_empty() {
            let w = queue.pop_front().unwrap();
            for item in self.linked_vec[w as usize].iter() {
                if visited[*item as usize] { continue; }
                prev[*item as usize] = w;
                if *item == t {
                    self.draw(&prev, s, t);
                    return;
                }
                visited[*item as usize] = true;
                queue.push_back(*item);
            }
        }
    }

    fn dfs(&self, s: i32, t: i32) {
        let mut found   = false;
        let mut prev    = vec![-1; self.v as usize];
        let mut visited = vec![false; self.v as usize];

        self.recur_dfs(s, t, &mut visited, &mut prev, &mut found);
        self.draw(&prev, s, t);
    }

    fn recur_dfs(&self,
                 s:       i32,
                 t:       i32,
                 visited: &mut Vec<bool>,
                 prev:    &mut Vec<i32>,
                 found:   &mut bool) {
        if *found == true { return; }
        visited[s as usize] = true;
        if s == t {
            *found = true;
            return;
        }
        for item in self.linked_vec[s as usize].iter() {
            if visited[*item as usize] { continue; }
            prev[*item as usize] = s;
            self.recur_dfs(*item, t, visited, prev, found);
        }
    }

    // 递归打印路径
    fn draw(&self, prev: &Vec<i32>, s: i32, t: i32) {
        if prev[t as usize] != -1 && s != t {
            self.draw(prev, s, prev[t as usize]);
        }

        println!("{} ->", t);
    }
}

fn main() {
    let mut graph = Graph::new(8);
    graph.add_edge(0, 1);
    graph.add_edge(0, 3);
    graph.add_edge(1, 2);
    graph.add_edge(1, 4);
    graph.add_edge(2, 5);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(4, 6);
    graph.add_edge(5, 7);
    graph.add_edge(6, 7);

    // Graph { v: 8, linked_vec: [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5, 6], [2, 4, 7], [4, 7], [5, 6]] }
    println!("{:?}", graph);
    graph.bfs(0, 7);
    println!("bfs=============");
    graph.bfs(1, 3);
    println!("bfs=============");

    graph.dfs(0, 7);
    println!("dfs=============");
    graph.dfs(1, 3);
    println!("dfs=============");
}
