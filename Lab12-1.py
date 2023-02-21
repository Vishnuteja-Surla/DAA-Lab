def isBipartite(V, adj):
	# vector to store colour of vertex
	# assigning all to -1 i.e. uncoloured
	# colours are either 0 or 1
	# for understanding take 0 as red and 1 as blue
	col = [-1]*(V)

	# queue for BFS storing {vertex , colour}
	q = []

	#loop incase graph is not connected
	for i in range(V):
	
		# if not coloured
		if (col[i] == -1):
		
			# colouring with 0 i.e. red
			q.append([i, 0])
			col[i] = 0
		
			while len(q) != 0:
				p = q[0]
				q.pop(0)
			
				# current vertex
				v = p[0]
				
				# colour of current vertex
				c = p[1]
				
				# traversing vertexes connected to current vertex
				for j in adj[v]:
				
					# if already coloured with parent vertex color
					# then bipartite graph is not possible
					if (col[j] == c):
						return False
				
					# if uncoloured
					if (col[j] == -1):
					
						# colouring with opposite color to that of parent
						if c == 1:
							col[j] = 0
						else:
							col[j] = 1
						q.append([j, col[j]])
	
	# if all vertexes are coloured such that
	# no two connected vertex have same colours
	return True

V, E = 4, 8

# adjacency list for storing graph
adj = []
adj.append([1,3])
adj.append([0,2])
adj.append([1,3])
adj.append([0,2])

ans = isBipartite(V, adj)

# returns 1 if bipartite graph is possible
if (ans):
	print("Yes")
	
# returns 0 if bipartite graph is not possible
else:
	print("No")
	
	# This code is contributed by divyesh072019.
