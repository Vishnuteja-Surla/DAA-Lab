#  Test for Connectedness

import collections

def bfs(graph, root):
    visited, queue = set(), collections.deque([root])
    visited.add(root)
    bfs_return_list = []
    while queue:
        vertex = queue.popleft()
        bfs_return_list.append(vertex)
        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)
    return bfs_return_list

if __name__ == '__main__':
    v_g = int(input("Enter the number of vertices in the graph : "))
    graph = dict()
    vertices = []
    for i in range(v_g):
        vertex = input(f"Enter the name of vertex-{i+1} : ")
        vertices.append(vertex)
        connected_vertices = input(f"Enter the vertices connected to vertex-{i+1} : ")
        connected_vertices = connected_vertices.split(", ")
        graph[vertex] = connected_vertices
    bfs_list = bfs(graph, vertices[0])
    print("Following is Breadth First Traversal : ", bfs_list)
    print("The Following is the list of vertices : ",vertices)
    if len(bfs_list) == len(vertices):
        print("The Graph is Connected")
    else:
        print("The Graph is Disconnected")