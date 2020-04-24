from dinic import *
from visualizer import visualize
import copy

nodes = {}

try:
    total = 0
    source = 'World'
    dest = 'Main Server'
    nodes[source] = Node(source)
    nodes[dest] = Node(dest)
    n = int(input("Enter number of countries: "))
    for i in range(n):
        name, allocation, incoming = input("Country Data ('Name Max_Alloc Incoming_Connections'): ").split(' ')
        total += int(allocation)
        nodes[name] = Node(name)
        nodes[source].addEdge(name, int(incoming))
        nodes[name].addEdge(dest, int(allocation))

    k = input("Enter number of edges: ")
    print("Enter <source> <target> <capacity>: ")
    for i in range(int(k)):
        line = input("")
        line = line.split(' ')
        if (len(line) == 3):
            nodes[line[0]].addEdge(line[1], int(line[2]))

    # Copy nodes
    before_nodes = copy.deepcopy(nodes)

    
    # Dinic's algorithm
    flow = dinic(source, dest, nodes)
    print("The number of servers allocated statically: {}".format(flow))
    print("The number of servers allocated dynamically: {}".format(total-flow))

    # Save the graph for visualization
    visualize(before_nodes, nodes, "output/problem.png", "output/solution.png")
except:
    print("Bad Input!")