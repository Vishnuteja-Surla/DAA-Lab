import sys


class Graph():

	def __init__(self, vertices):
		self.V = vertices
		self.graph = [[0 for column in range(vertices)]
					for row in range(vertices)]

	def printSolution(self, dist):
		print("Vertex \tDistance from Source")
		for node in range(self.V):
			print(node, "\t", dist[node])
	
	def minDistance(self, dist, sptSet):
		min = sys.maxsize
		for u in range(self.V):
			if dist[u] < min and sptSet[u] == False:
				min = dist[u]
				min_index = u
		return min_index

	def dijkstra(self, src):

		dist = [sys.maxsize] * self.V
		dist[src] = 0
		sptSet = [False] * self.V

		for cout in range(self.V):
			x = self.minDistance(dist, sptSet)
			sptSet[x] = True
			for y in range(self.V):
				if self.graph[x][y] > 0 and sptSet[y] == False and \
						dist[y] > dist[x] + self.graph[x][y]:
					dist[y] = dist[x] + self.graph[x][y]

		self.printSolution(dist)


# Driver's code
if __name__ == "__main__":
	no_of_vertices = int(input("Enter the number of nodes in Graph : "))
	g = Graph(no_of_vertices)
	temp = []
	for i in range(no_of_vertices):
		row = []
		for j in range(no_of_vertices):
			weight = int(input(f"Enter the weight of edge between Node-{i+1} and Node-{j+1} : "))
			row.append(weight)
		temp.append(row)
	g.graph = temp.copy()
	g.dijkstra(0)