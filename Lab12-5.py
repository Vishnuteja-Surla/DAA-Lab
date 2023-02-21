# Python program to find bridges in a given undirected graph

from collections import defaultdict
class Graph:
	def __init__(self,vertices):
		self.V= vertices
		self.graph = defaultdict(list)
		self.Time = 0
	
	def addEdge(self,u,v):
		self.graph[u].append(v)
		self.graph[v].append(u)
	
	def bridgeUtil(self,u, visited, parent, low, disc):
		visited[u]= True
		disc[u] = self.Time
		low[u] = self.Time
		self.Time += 1
		for v in self.graph[u]:
			if visited[v] == False :
				parent[v] = u
				self.bridgeUtil(v, visited, parent, low, disc)
				low[u] = min(low[u], low[v])
				if low[v] > disc[u]:
					print ("%d %d" %(u,v))
			elif v != parent[u]:
				low[u] = min(low[u], disc[v])

	def bridge(self):
		visited = [False] * (self.V)
		disc = [float("Inf")] * (self.V)
		low = [float("Inf")] * (self.V)
		parent = [-1] * (self.V)
		for i in range(self.V):
			if visited[i] == False:
				self.bridgeUtil(i, visited, parent, low, disc)
		

# Driver Code
no_of_vertices = int(input("Enter the number of vertices in the graph : "))
g1 = Graph(no_of_vertices)
while 1:
    choice = input("Would you like to add an edge? Press 1 for yes else taken as no : ")
    if choice=='1':
        v1 = int(input("Enter the number of vertex-1 : "))
        v2 = int(input("Enter the number of vertex-2 : "))
        g1.addEdge(v1,v2)
    else:
        break
print ("Bridges in first graph ")
g1.bridge()