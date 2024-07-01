import matplotlib.pyplot as plt
import networkx as nx

# Create a directed graph
G = nx.DiGraph()

# Add nodes representing clients, servers, and intermediate nodes
nodes = ['Client1', 'Client2', 'Server1', 'Server2', 'Intermediate1', 'Intermediate2']
G.add_nodes_from(nodes)

# Add edges representing connections and network coding
edges = [('Client1', 'Intermediate1'), ('Client2', 'Intermediate1'),
         ('Client1', 'Intermediate2'), ('Client2', 'Intermediate2'),
         ('Intermediate1', 'Server1'), ('Intermediate1', 'Server2'),
         ('Intermediate2', 'Server1'), ('Intermediate2', 'Server2')]
G.add_edges_from(edges)

# Define positions for a visually appealing layout
pos = {
    'Client1': (0, 1), 'Client2': (0, -1),
    'Intermediate1': (1, 0.5), 'Intermediate2': (1, -0.5),
    'Server1': (2, 1), 'Server2': (2, -1)
}

# Draw the graph
plt.figure(figsize=(10, 6))
nx.draw(G, pos, with_labels=True, node_size=3000, node_color="skyblue", arrows=True)
plt.title('Network Coding for Reduced Web Response Time')

# Save the figure to a file
plt.savefig('network_coding_diagram.png')
