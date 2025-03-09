import sys
from queue import LifoQueue
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

def dfsOfGraph(nodes, start, adj):
    visited = [False]*nodes
    visited[start]=True
    stack=LifoQueue()  # Using a list as a stack (LIFO behavior)
    stack.put(start)
    dfs =[]
    
    while not stack.empty():
        node=stack.get()
        dfs.append(node)
        
        for it in adj[node]:
            if not visited[it]:
                visited[it]=True
                stack.put(it)
    return dfs
# Read input
n, m = map(int, input().split())
adj = [[] for _ in range(n)]  # 0-based index

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    # adj[v].append(u)  # Uncomment if the graph is undirected

# Run DFS from node 0
list_result = dfsOfGraph(6, 0, adj)  # Same as C++ version
print(*list_result)  # Print result space-separated


#for input
# 6 9
# 0 1
# 1 2
# 2 3
# 3 4
# 4 5
# 0 2
# 1 3
# 4 1
# 4 0