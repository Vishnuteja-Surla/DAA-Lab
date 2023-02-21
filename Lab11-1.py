# A Python3 program for Prim's Minimum Spanning Tree (MST) algorithm.

import sys


class Graph():

	def __init__(self, vertices):
		self.V = vertices
		self.graph = [[0 for column in range(vertices)]
					for row in range(vertices)]
	def printMST(self, parent):
		print("Edge \tWeight")
		for i in range(1, self.V):
			print(parent[i], "-", i, "\t", self.graph[i][parent[i]])

	def minKey(self, key, mstSet):
		min = sys.maxsize

		for v in range(self.V):
			if key[v] < min and mstSet[v] == False:
				min = key[v]
				min_index = v

		return min_index

	def primMST(self):
		key = [sys.maxsize] * self.V
		parent = [None] * self.V 
		mstSet = [False] * self.V

		parent[0] = -1
		for cout in range(self.V):
			u = self.minKey(key, mstSet)
			mstSet[u] = True
			for v in range(self.V):
				if self.graph[u][v] > 0 and mstSet[v] == False and key[v] > self.graph[u][v]:
					key[v] = self.graph[u][v]
					parent[v] = u

		self.printMST(parent)


# Driver's code
if __name__ == '__main__':
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
	g.primMST()
