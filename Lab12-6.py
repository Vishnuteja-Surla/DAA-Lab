# Python3 program to find out whether a given graph is Bipartite or not

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
	
# Driver Code

V = int(input("Enter the number of nodes in Graph : "))
G = []
for i in range(V):
	row = []
	for j in range(V):
		weight = int(input(f"Is there an edge between Node-{i+1} and Node-{j+1}? 1 if yes and 0 if no : "))
		row.append(weight)
	G.append(row)

if containsOdd(G, 0):
	print("Yes")
else:
	print("No")