# A Python3 program for finding number of triangles in an Undirected Graph.
def multiply(A, B, C):
	global V
	for i in range(V):
		for j in range(V):
			C[i][j] = 0
			for k in range(V):
				C[i][j] += A[i][k] * B[k][j]

def getTrace(graph):
	global V
	trace = 0
	for i in range(V):
		trace += graph[i][i]
	return trace

def triangleInGraph(graph):
	global V
	aux2 = [[None] * V for i in range(V)]
	aux3 = [[None] * V for i in range(V)]
	for i in range(V):
		for j in range(V):
			aux2[i][j] = aux3[i][j] = 0
	multiply(graph, graph, aux2)
	multiply(graph, aux2, aux3)

	trace = getTrace(aux3)
	return trace // 6

# Driver Code
V = int(input("Enter the number of nodes in Graph : "))
G = []
for i in range(V):
	row = []
	for j in range(V):
		weight = int(input(f"Is there an edge between Node-{i+1} and Node-{j+1}? 1 if yes and 0 if no : "))
		row.append(weight)
	G.append(row)

print("Total number of Triangle in Graph : ",triangleInGraph(G))