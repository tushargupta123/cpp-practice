#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V; 
    int E; 
    vector<pair<int, int>> *adj;

    Graph(int num_vertices, int num_edges) {
        V = num_vertices;
        E = num_edges;
        adj = new vector<pair<int, int>>[num_vertices];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    vector<int> topSort(int src) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; ++i) {
            for (pair<int, int> node : adj[i]) {
                indegree[node.first]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> topSortOrdering;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topSortOrdering.push_back(u);
            for (pair<int, int> node : adj[u]) {
                indegree[node.first]--;
                if (indegree[node.first] == 0) {
                    q.push(node.first);
                }
            }
        }
        return topSortOrdering;
    }

    void findShortestPathInDAG(int src) {
        vector<int> distances(V, INT_MAX);
        vector<int> topSortOrdering = topSort(src);
        distances[src] = 0;
        for (int x : topSortOrdering) {
            if (distances[x] != INT_MAX) {
                for (pair<int, int> adjNode : adj[x]) {
                    if (distances[adjNode.first] > distances[x] + adjNode.second) {
                        distances[adjNode.first] = distances[x] + adjNode.second;
                    }
                }
            }
        }
        cout << "The distances from the src node are: ";
        for (int i = 0; i < V; ++i) {
            if (distances[i] == INT_MAX)
                cout << "INF ";
            else
                cout << distances[i] << " ";
        }
    }
};

int main() {
    int num_vertices = 6;
    int num_edges = 9;
    Graph G(num_vertices, num_edges);
    G.addEdge(1, 3, 6);
    G.addEdge(1, 2, 2);
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(2, 3, 7);
    G.addEdge(4, 5, -2);
    int src = 1;
    G.findShortestPathInDAG(src);

    return 0;
}
