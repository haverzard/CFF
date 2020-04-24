from queue import Queue, LifoQueue
import sys

class Node:
    def __init__(self, name):
        self.name = name
        self.adj = {}
    
    def addEdge(self, name, cap):
        self.adj[name] = cap

# BFS for setup level
def bfs(source, dest, nodes):
    q = Queue()
    q.put(source)
    level = {source: 0}
    visited = {}
    while (not q.empty()):
        name = q.get()
        if (name == dest):
            break
        if (name not in visited):
            visited[name] = True
            for x, cap in nodes[name].adj.items():
                if (x not in level and cap > 0):
                    level[x] = level[name] + 1
                    q.put(x)
    return (name == dest, level)

# DFS for sending flow
def dfsFlow(source, dest, level, depth, flow, nodes):
    if (source == dest):
        return flow
    sum = 0
    for name, cap in nodes[source].adj.items():
        if (name in level and level[name] == depth+1):
            t_flow = min(cap,flow)
            t_flow = dfsFlow(name, dest, level, depth+1, t_flow, nodes)
            nodes[source].adj[name] -= t_flow
            if (source not in nodes[name].adj):
                nodes[name].adj[source] = t_flow
            else:
                nodes[name].adj[source] += t_flow
            sum += t_flow
    return sum

# Dinic's Algorithm
def dinic(source, dest, nodes):
    possible, level = bfs(source, dest, nodes)
    flow = 0
    while (possible):
        temp = dfsFlow(source, dest, level, 0, sys.maxsize, nodes)
        if (temp <= 0):
            break
        flow += temp
        possible, level = bfs(source, dest, nodes)
    return flow