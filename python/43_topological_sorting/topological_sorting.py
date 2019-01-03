"""
    Author: Wenru Dong
"""

from collections import deque
from itertools import filterfalse

class Graph:
    def __init__(self, num_vertices: int):
        self._num_vertices = num_vertices
        self._adjacency = [[] for _ in range(num_vertices)]
    
    def add_edge(self, s: int, t: int) -> None:
        self._adjacency[s].append(t)

    def tsort_by_kahn(self) -> None:
        in_degree = [0] * self._num_vertices
        for v in range(self._num_vertices):
            if len(self._adjacency[v]):
                for neighbour in self._adjacency[v]:
                    in_degree[neighbour] += 1
        q = deque(filterfalse(lambda x: in_degree[x], range(self._num_vertices)))
        while q:
            v = q.popleft()
            print(f"{v} -> ", end="")
            for neighbour in self._adjacency[v]:
                in_degree[neighbour] -= 1
                if not in_degree[neighbour]:
                    q.append(neighbour)
        print("\b\b\b   ")

    def tsort_by_dfs(self) -> None:
        inverse_adjacency = [[] for _ in range(self._num_vertices)]
        for v in range(self._num_vertices):
            if len(self._adjacency[v]):
                for neighbour in self._adjacency[v]:
                    inverse_adjacency[neighbour].append(v)
        visited = [False] * self._num_vertices

        def dfs(vertex: int) -> None:
            if len(inverse_adjacency[vertex]):
                for v in inverse_adjacency[vertex]:
                    if not visited[v]:
                        visited[v] = True
                        dfs(v)
            print(f"{vertex} -> ", end="")
        
        for v in range(self._num_vertices):
            if not visited[v]:
                visited[v] = True
                dfs(v)
        
        print("\b\b\b   ")


if __name__ == "__main__":

    dag = Graph(4)
    dag.add_edge(1, 0)
    dag.add_edge(2, 1)
    dag.add_edge(1, 3)
    dag.tsort_by_kahn()
    dag.tsort_by_dfs()
