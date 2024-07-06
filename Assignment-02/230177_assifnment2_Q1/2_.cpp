#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

typedef pair<long long, int> pii;

void dijkstra(int n, int e, vector<long long>& distances, vector<vector<pii>>& adj_list) {
    // Initialize distances to infinity
    distances.assign(n + 1, LLONG_MAX);
    distances[1] = 0;  // Distance to the source node itself is zero

    // Priority queue to process the nodes with the smallest distance first
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});  // Push the source node with distance 0

    vector<bool> visited(n + 1, false);

    while (!pq.empty()) {
        long long now_dist = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();

        if (visited[now_node]) {
            continue;
        }

        visited[now_node] = true;

        for (const auto& edge : adj_list[now_node]) {
            int next_node = edge.first;
            long long weight = edge.second;
            long long dista = now_dist + weight;

            if (dista < distances[next_node]) {
                distances[next_node] = dista;
                pq.push({dista, next_node});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj_list(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj_list[a].emplace_back(b, c);
    }

    vector<long long> distances;
    dijkstra(n, m, distances, adj_list);

    for (int i = 1; i <= n; i++) {
        cout << distances[i] << " ";
    }
    cout << endl;

    return 0;
}
