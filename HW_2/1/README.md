# HW_2 - DFS Traversals Collection

This project implements a collection of Depth-First Search traversals for a directed, unweighted, simple graph (no multiple edges) with indexed vertices (`0` to `n-1`). The class allows analyzing DFS edges and comparing different traversals.

## Features

### Graph Representation

- Directed, unweighted, simple graph.
- Vertices are indexed from `0` to `n-1`.
- Edges are stored in adjacency lists.

### DFS Traversals

The `DfsTraversalsCollection` class supports DFS traversals from a given start vertex. It provides functions to retrieve the following types of edges:

- **Tree edges** – edges part of the DFS tree.
- **Back edges** – edges connecting a vertex to an ancestor in the DFS tree.
- **Forward edges** – edges connecting a vertex to a descendant in the DFS tree (not a tree edge).
- **Cross edges** – all other edges connecting nodes in different DFS branches.

### Functionalities

- Return all edges of each type: tree, back, forward, and cross.
- `operator<<` to print vertices in the order of traversal (space-separated).
- Supports iterators for traversing all DFS objects in ascending order.
- Comparison operator for DFS traversals:
  - Given traversals `a = [a1, a2, ..., an]` and `b = [b1, b2, ..., bn]`,  
    ```
    a < b ⇔ a1 < b1 or (a1 = b1 and a2 < b2) or (a1 = b1, a2 = b2, a3 < b3) ...
    ```
