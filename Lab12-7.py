from collections import defaultdict
import queue

def containsOdd(G, src):
	global V
	colorArr = [-1] * V
	colorArr[src] = 1
	q = queue.Queue()
	q.put(src)
	while (not q.empty()):
		u = q.get()
		if (G[u][u] == 1):
			return True
		for v in range(V):
			if (G[u][v] and colorArr[v] == -1):
				colorArr[v] = 1 - colorArr[u]
				q.put(v)
			elif (G[u][v] and
				colorArr[v] == colorArr[u]):
				return True
	return False


class Graph:

	def __init__(self, vertices):
		self.V = vertices
		self.graph = defaultdict(list)

	def addEdge(self, v, w):
		self.graph[v].append(w)
		self.graph[w].append(v)

	def isCyclicUtil(self, v, visited, parent):
		visited[v] = True
		for i in self.graph[v]:
			if visited[i] == False:
				if(self.isCyclicUtil(i, visited, v)):
					return True
			elif parent != i:
				return True
		return False

	def isCyclic(self):
		visited = [False]*(self.V)
		for i in range(self.V):
			if visited[i] == False:
				if(self.isCyclicUtil
				(i, visited, -1)) == True:
					return True

		return False

#Driver Code
no_of_vertices = int(input("Enter the number of vertices in the graph : "))
g = Graph(no_of_vertices)
while 1:
    choice = input("Would you like to add an edge? Press 1 for yes else taken as no : ")
    if choice=='1':
        v1 = int(input("Enter the number of vertex-1 : "))
        v2 = int(input("Enter the number of vertex-2 : "))
        g.addEdge(v1,v2)
    else:
        break

if g.isCyclic() and not containsOdd(g,0):
	print("Graph contains even cycle")
else:
	print("Graph doesn't contain even cycle ")
