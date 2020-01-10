"""
    Dijkstra algorithm

    Author: Wenru Dong
"""

from dataclasses import dataclass
from queue import PriorityQueue

@dataclass
class Edge:
    start_id: int
    end_id: int
    weight: int

@dataclass(order=True)
class Vertex:
    distance_to_start = float("inf")
    vertex_id: int

class Graph:

    REMOVED = '<removed-task>'

    def __init__(self, num_vertices: int):
        self._num_vertices = num_vertices
        self._adjacency = [[] for _ in range(num_vertices)]
        self._entry_finder = {}
    
    def add_edge(self, from_vertex: int, to_vertex: int, weight: int) -> None:
        self._adjacency[from_vertex].append(Edge(from_vertex, to_vertex, weight))

    def update_priorityqueue(self, vertex_id):
        poped_entry = self._entry_finder.pop(vertex_id)
        poped_entry[-1] = Graph.REMOVED

    def dijkstra(self, from_vertex: int, to_vertex: int) -> None:
        vertices = [Vertex(i) for i in range(self._num_vertices)]
        vertices[from_vertex].distance_to_start = 0
        visited = [False] * self._num_vertices
        predecessor = [-1] * self._num_vertices
        
        q = PriorityQueue()
        entry = [vertices[from_vertex].distance_to_start, vertices[from_vertex]]
        q.put(entry)
        self._entry_finder[from_vertex] = entry

        visited[from_vertex] = True
        while not q.empty():
            min_vertex = q.get()[1]
            if min_vertex is not Graph.REMOVED:
                del self._entry_finder[min_vertex.vertex_id]
                if min_vertex.vertex_id == to_vertex:
                    break
                for edge in self._adjacency[min_vertex.vertex_id]:
                    next_vertex = vertices[edge.end_id]
                    if min_vertex.distance_to_start + edge.weight < next_vertex.distance_to_start:
                        next_vertex.distance_to_start = min_vertex.distance_to_start + edge.weight
                        predecessor[next_vertex.vertex_id] = min_vertex.vertex_id
                        entry = [next_vertex.distance_to_start, next_vertex]
                        if not visited[next_vertex.vertex_id]:
                            visited[next_vertex.vertex_id] = True
                        else:
                            self.update_priorityqueue(next_vertex.vertex_id)
                        q.put(entry)
                        self._entry_finder[next_vertex.vertex_id] = entry
            
        path = lambda x: path(predecessor[x]) + [str(x)] if from_vertex != x else [str(from_vertex)]
        print("->".join(path(to_vertex)))


if __name__ == "__main__":
    graph = Graph(6)
    graph.add_edge(0, 1, 10)
    graph.add_edge(0, 4, 15)
    graph.add_edge(1, 2, 15)
    graph.add_edge(1, 3, 2)
    graph.add_edge(2, 5, 5)
    graph.add_edge(3, 2, 1)
    graph.add_edge(3, 5, 12)
    graph.add_edge(4, 5, 10)
    graph.dijkstra(0, 5)
