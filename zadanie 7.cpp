#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int destination;
    int weight;
};

class Graph {
public:
    int vertices;
    vector<vector<Edge>> adjacencyList;

    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].push_back({ destination, weight });
        adjacencyList[destination].push_back({ source, weight }); // dla grafu nieskierowanego
    }

    vector<int> shortestPath(int start, int end) {
        vector<int> distance(vertices, INT_MAX);
        vector<int> path(vertices, -1);
        distance[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, start });

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& edge : adjacencyList[u]) {
                int v = edge.destination;
                int weight = edge.weight;

                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    path[v] = u;
                    pq.push({ distance[v], v });
                }
            }
        }

        // Odtworzenie najkrótszej ścieżki
        vector<int> shortestPath;
        int current = end;
        while (current != -1) {
            shortestPath.push_back(current);
            current = path[current];
        }

        reverse(shortestPath.begin(), shortestPath.end());
        return shortestPath;
    }
};

int main() {
    // Przykład użycia
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 3);
    g.addEdge(0, 4, 7);

    vector<int> path = g.shortestPath(0, 4);

    cout << "Najkrotsza sciezka: ";
    for (int vertex : path) {
        cout << vertex << " ";
    }

    return 0;
}
