# Shortest Path Finding Algorithm - Dijkstra's Algorithm in C++

## Overview

This project implements a pathfinding algorithm based on Dijkstra’s algorithm in C++ to find the shortest path between two nodes in a weighted graph. It utilizes priority queues and adjacency lists to optimise performance, resulting in significantly faster execution compared to basic matrix-based implementation.

## Features

- **Shortest Path Calculation**: Finds the shortest path between two specified nodes in a weighted graph.
- **Optimized Performance**: Uses a priority queue for efficient node selection and adjacency lists for storing graph edges.
- **Graph Representation**: Nodes and edges are represented using an adjacency list for space efficiency.


## Algorithm

The project uses **Dijkstra’s Algorithm** which is an efficient way of finding the shortest path in a graph with non-negative weights. The main steps include:

1. **Initialization**: Set the distance to the source node as 0 and all others as infinity.
2. **Priority Queue**: Use a priority queue to explore nodes with the smallest known distance first.
3. **Relaxation**: For each neighboring node if a shorter path is found update the node’s distance.
4. **Termination**: The algorithm terminates after computing the shortest paths from the source node to all other nodes.

## Data Structures Used

- **Priority Queue**: This is used to keep track of nodes with the smallest tentative distance, which allows the algorithm to efficiently explore the shortest path first.
- **Adjacency List**: A graph is represented using an adjacency list, where each node stores a list of its neighboring nodes and the corresponding edge weights.

## Performance

- The program was optimized by using a **priority queue** (min-heap) to fetch the next node with the smallest tentative distance.
- The graph is stored as an **adjacency list**, ensuring efficient space complexity compared to other representations like adjacency matrices.


## Technologies Used

- C++ 11

### Setup Instructions

1. Clone the repository.
2. Run the project using a compatible IDE.
3. Modify the graph data in the code (adjacency list) as desired.
4. The project will open up a CLI showing the shortest distance between each node.