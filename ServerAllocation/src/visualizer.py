import matplotlib.pyplot as plt
import networkx as nx

source = 'World'
dest = 'Main Server'

# Graph Visualization
def visualize(before_nodes, nodes, problem_image, solution_image):
    # Initiate Graph
    G = nx.DiGraph()
    G2 = nx.DiGraph()
    pos = nx.spring_layout(G)
    pos2 = nx.spring_layout(G2)
    G.add_nodes_from(before_nodes.keys())
    G2.add_nodes_from(before_nodes.keys())
    n = len(before_nodes.keys())-2
    x = 1
    y = n//2
    i = 0
    
    # Edges construction
    for name in before_nodes.keys():
        for k in before_nodes[name].adj.keys():
            G2.add_edge(name,k,weight=before_nodes[name].adj[k])
            if (name in nodes[k].adj):
                before_nodes[name].adj[k] = nodes[k].adj[name]
                G.add_edge(name,k,weight=before_nodes[name].adj[k])
            else:
                before_nodes[name].adj[k] = 0
        # Position setter for countries
        if (i > 1 and i < n+2):
            pos[name] = [x,y]
            pos2[name] = [x,y]
            x += 1
            y -= 1
        i += 1

    # Position setter for source and sink
    pos[source] = [0,((n+1)%2)*0.5]
    pos[dest] = [n+1,((n+1)%2)*0.5]
    pos2[source] = [0,((n+1)%2)*0.5]
    pos2[dest] = [n+1,((n+1)%2)*0.5]
    
    # Graph settings
    weights = nx.get_edge_attributes(G, "weight")
    nx.draw_networkx(G, pos, with_labels=True, font_size=5, node_size=300, node_color=range(n+2), cmap='spring', connectionstyle='arc3, rad=0.1')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=weights)

    # Output
    plt.title("Server Allocation Graph - Solution")
    plt.gcf().set_size_inches(10,8)
    plt.savefig(solution_image)

    # Graph settings 2
    weights = nx.get_edge_attributes(G2, "weight")
    nx.draw_networkx(G2, pos2, with_labels=True, font_size=5, node_size=300, node_color=range(n+2), cmap='spring', connectionstyle='arc3, rad=0.1')
    nx.draw_networkx_edge_labels(G2, pos2, edge_labels=weights)

    plt.title("Server Allocation Graph - Problem")
    plt.gcf().set_size_inches(10,8)
    plt.savefig(problem_image)