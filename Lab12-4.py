#  Test for Articulation Points

import collections

# BFS algorithm
def bfs(graph, root):

    visited, queue = set(), collections.deque([root])
    visited.add(root)
    bfs_return_list = []

    while queue:

        # Dequeue a vertex from queue
        vertex = queue.popleft()
        bfs_return_list.append(vertex)

        # If not visited, mark it as visited, and
        # enqueue it
        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)
    return bfs_return_list

if __name__ == '__main__':
    v_g = int(input("Enter the number of vertices in the graph : "))
    graph = dict()
    temp = dict()
    vertices = []
    for i in range(v_g):
        vertex = input(f"Enter the name of vertex-{i+1} : ")
        vertices.append(vertex)
        connected_vertices = input(f"Enter the vertices connected to vertex-{i+1} : ")
        connected_vertices = connected_vertices.split(", ")
        graph[vertex] = connected_vertices
    temp = graph.copy()
    articulation_points = []
    for i in range(len(vertices)):
        vertex = vertices[i]
        connected_vertices = graph[vertex]
        vertices.remove(vertex)
        graph.pop(vertex)
        for j in graph:
            if vertex in graph[j]:
                graph[j].remove(vertex)
        bfs_list = bfs(graph,vertices[0])
        if len(bfs_list) != len(vertices):
            articulation_points.append(vertex)
        vertices.insert(i,vertex)
        graph = temp.copy()
    print("Articulation Points : ",articulation_points)