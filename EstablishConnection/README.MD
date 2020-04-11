# Route Planning
## Description
Find the number of connections we need to connect all the nodes.
## The Idea
We iterate all nodes (check if visited or not yet) and visit them (if not visited yet). For each visit, do BFS to visit the connected nodes. We count the number of visits from the nodes' iteration and that is the answer (remember to minus 1).
## Time Complexity
O(V+E)
## Solutions
'''solution.cpp'''