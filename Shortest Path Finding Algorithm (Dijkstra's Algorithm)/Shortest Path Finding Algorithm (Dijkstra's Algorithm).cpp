#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();    // Define infinity as the maximum int value
typedef pair<int, int> Edge;                    // Pair representing (weight, vertex)
typedef vector<vector<Edge>> Graph;             // Graph represented as adjacency list

// Dijkstra's algorithm implementation to find shortest paths from source
void runDijkstra(const Graph& graph, int source) {
    int n = static_cast<int>(graph.size());    // Number of vertices in the graph
    vector<int> distance(n, INF);               // Initialize distances to all vertices as infinite
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap; // Min-heap to pick vertex with smallest distance

    distance[source] = 0;                       // Distance from source to itself is zero
    minHeap.push(make_pair(0, source));        // Push source vertex into priority queue

    while (!minHeap.empty()) {
        int dist = minHeap.top().first;        // Current shortest distance to vertex
        int u = minHeap.top().second;           // Vertex with current shortest distance
        minHeap.pop();

        // If we have already found a better path before, skip this vertex
        if (dist > distance[u]) continue;

        const vector<Edge>& neighbors = graph[u];  // Explore all neighbors of vertex u
        for (size_t i = 0; i < neighbors.size(); ++i) {
            int weight = neighbors[i].first;       // Edge weight from u to neighbor
            int v = neighbors[i].second;            // Neighbor vertex

            // Relaxation step: update distance if shorter path found
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                minHeap.push(make_pair(distance[v], v));  // Push updated distance and vertex into min-heap
            }
        }
    }

    // Output shortest distances from source to all vertices
    cout << "Vertex\tShortest Distance from Source\n";
    for (int i = 0; i < n; ++i) {
        cout << char('A' + i) << "\t\t" << distance[i] << '\n';
    }
}

int main() {
    // Graph represented as adjacency list:
    // Each element in the outer vector corresponds to a node
    // Each inner pair represents {weight, neighbor_node}
    Graph graph = {
        { {1,1}, {2,2} },                // Edges from node A (0)
        { {1,0}, {1,2}, {3,4} },         // Edges from node B (1)
        { {2,0}, {1,1}, {2,3}, {2,4} },  // Edges from node C (2)
        { {2,2}, {1,4}, {1,5} },         // Edges from node D (3)
        { {3,1}, {2,2}, {1,3}, {2,5} },  // Edges from node E (4)
        { {1,3}, {2,4} }                 // Edges from node F (5)
    };

    runDijkstra(graph, 0);  // Run shortest path from node A (index 0)

    return 0;
}