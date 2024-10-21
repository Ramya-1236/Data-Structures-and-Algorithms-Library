#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max()); // Initialize distances
    distance[start] = 0; // Distance from start to itself is 0

    // Min-heap to store (distance, vertex) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // Start with the initial vertex

    while (!pq.empty()) {
        int currentDistance = pq.top().first; // Current shortest distance
        int currentVertex = pq.top().second; // Current vertex
        pq.pop();

        // Check each neighbor of the current vertex
        for (auto& neighbor : graph[currentVertex]) {
            int nextVertex = neighbor.first; // Neighbor vertex
            int edgeWeight = neighbor.second; // Weight of edge

            // If a shorter path is found
            if (currentDistance + edgeWeight < distance[nextVertex]) {
                distance[nextVertex] = currentDistance + edgeWeight; // Update distance
                pq.push({distance[nextVertex], nextVertex}); // Add to priority queue
            }
        }
    }

    // Print the results
    cout << "Vertex Distance from Source:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    // Create a simple graph as an adjacency list
    int n = 5; // Number of vertices
    vector<vector<pair<int, int>>> graph(n);

    // Adding edges (from, to, weight)
    graph[0].push_back({1, 10});
    graph[0].push_back({2, 3});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 2});
    graph[2].push_back({1, 4});
    graph[2].push_back({3, 8});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 7});
    graph[4].push_back({3, 9});

    int startVertex = 0; // Starting vertex for Dijkstra's algorithm
    dijkstra(graph, startVertex); // Run the algorithm

    return 0; // End of program
}
