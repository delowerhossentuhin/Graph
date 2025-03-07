import sys
sys.stdin=open('input.txt','r')
sys.stdout=open('output.txt','w')

n,m=map(int,input().split()) # n = number of nodes, m = number of edges


adj=[]
for i in range(n+1):
    temp=[]
    for j in range(n+1):
        temp.append(0)
    adj.append(temp)

for row in adj:
    print(row)

for i in range(m):
    u,v=map(int,input().split())
    adj[u][v]=1
    adj[v][u]=1 # this line is only for undirected graph
print("Printing Graph: ")
for row in adj:
    print(row)