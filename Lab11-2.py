# Python program for Kruskal's algorithm

class Graph:

	def __init__(self, vertices):
		self.V = vertices
		self.graph = []

	def addEdge(self, u, v, w):
		self.graph.append([u, v, w])

	def find(self, parent, i):
		if parent[i] != i:
			parent[i] = self.find(parent, parent[i])
		return parent[i]
	
	def union(self, parent, rank, x, y):
		if rank[x] < rank[y]:
			parent[x] = y
		elif rank[x] > rank[y]:
			parent[y] = x
		else:
			parent[y] = x
			rank[x] += 1

	def KruskalMST(self):
		result = []
		i = 0
		e = 0
		self.graph = sorted(self.graph,
							key=lambda item: item[2])

		parent = []
		rank = []
		for node in range(self.V):
			parent.append(node)
			rank.append(0)
		while e < self.V - 1:
			u, v, w = self.graph[i]
			i = i + 1
			x = self.find(parent, u)
			y = self.find(parent, v)
			if x != y:
				e = e + 1
				result.append([u, v, w])
				self.union(parent, rank, x, y)

		minimumCost = 0
		print("Edges in the constructed MST")
		for u, v, weight in result:
			minimumCost += weight
			print("%d -- %d == %d" % (u, v, weight))
		print("Minimum Spanning Tree", minimumCost)


# Driver's code
if __name__ == '__main__':
	V = int(input("Enter the number of nodes : "))
	g = Graph(V)
	while 1:
		choice = input("Would you like to add an edge? Press 1 for yes else taken as no : ")
		if choice=='1':
			v1 = int(input("Enter the number of vertex-1 : "))
			v2 = int(input("Enter the number of vertex-2 : "))
			w = float(input("Enter the weight of the edge : "))
			g.addEdge(v1,v2,w)
		else:
			break
	g.KruskalMST()