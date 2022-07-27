**Depth First Search on 2-d grid**
- DFS on a 2-d grid. Recursively f(i+1,j),f(i-1,j),f(i,j+1), f(i,j-1).
- DFS on 2-d grid to find out connected components. 
- Variation of connected components: keep track of nodes in each connected component.
- Variation of connected components: check if any connected component lies on edge.
- Variation of connected components: find sub-islands in second grid from first grid.

**DFS on graph**
- DFS with backtracking. https://leetcode.com/problems/all-paths-from-source-to-target/
- DFS standard.
- DFS standard, find the number of connected components.
- Longest path in a graph. Update path inside neighbors for loop.
- Bi-partite graph https://leetcode.com/problems/is-graph-bipartite
- Sort the connected components. 

**Topological Sort**
- Kahn's Algorithm using queue.
- Also used to find centroid or minimum height trees or root trees

**Breadth First Search on 2-d grid**
- Multi Source BFS - push in all the 0's or 1's initially into queue and then start BFS simultaneously from them.
- Variation of multi-source bfs: go backwards. if you are asked to find distance from 0's consider starting from 1. works sometimes.
- Find common cells in BFS: do BFS on both and then check visited cell which all are common.
- Keep a distance[][] array and update it during BFS.
- https://leetcode.com/problems/shortest-bridge/ DFS + BFS (Find one connected components, enumerate elements in it as 2's then push them in a queue, do multisource BFS till you reach the other component. Steps is your answer.)
- Cycle finding algorithm. gray-white-black algorithm.
- Assign properties to edges, like negative or positive.
- 0-1 BFS (https://cp-algorithms.com/graph/01_bfs.html,https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)
- BFS with binary search (https://leetcode.com/problems/path-with-minimum-effort/)


**BFS on graph**
- https://leetcode.com/problems/shortest-path-with-alternating-colors/ store multiple information on queue, for example, here store the color as well.
- Need two states. https://leetcode.com/problems/minimum-jumps-to-reach-home/
- Standard BFS. Word Ladder types.

**Dijisktra**
- All edge weights must be positive. Greedy Algorithm. O(E*logV)
- Keep a distance array, prioriry_queue<int,int>(index,distance), like bfs push into pq and loop till not empty, iterate neighbors, relax edge, add key value pair to queue.
- Another variant, you need to find shortest path and not distance. Keep a prev array and iterate from dest backward.
- Stopping early: If we encounter destination, return. More iteration will not give a better approach. 
- https://leetcode.com/problems/network-delay-time/
- Variation: https://leetcode.com/problems/cheapest-flights-within-k-stops/solution/ Keep track of stops as well.
- https://www.youtube.com/watch?v=pSqmAO-m7Lk&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=19&ab_channel=WilliamFiset

**Disjoint Set Union**
- Useful to find valid tree, find out cycles etc.
- https://cp-algorithms.com/data_structures/disjoint_set_union.html#naive-implementation
- https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

**Minimum Spanning Tree**
- If we model the cities and connections as a graph, each connection is an edge (undirected) and each city is a node of the graph. We need to find a subset of edges which connects all the nodes of the graph with the minimum possible total weight. This is by definition the Minimum Spanning Tree or MST of a graph.
- https://www.youtube.com/watch?v=JZBQLXgSGfs
- Implemented using Disjoint Set Union (Kruskal's)
- https://leetcode.com/problems/connecting-cities-with-minimum-cost/solution/

**Articulation Points and Bridges**
- https://leetcode.com/problems/critical-connections-in-a-network/
- https://www.youtube.com/watch?v=2kREIkF9UAs&ab_channel=TusharRoy-CodingMadeSimple
