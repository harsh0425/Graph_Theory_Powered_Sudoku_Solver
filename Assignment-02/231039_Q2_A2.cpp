#include <bits/stdc++.h>
#include <queue>
#include <iostream>

using namespace std;


typedef long long ll;
typedef vector<int> vi;
#define iPair pair<ll,ll>
#define For(i, n) for (int i = 0; i < n; i++)
#define aFor(i, a, n) for (int i = a; i < n; i++)

map<int, vector<iPair>> mp;

void addEdge(vector<iPair> (&graph)[], ll u, ll v, ll w) {
    graph[u].push_back(make_pair(v, w));
}

void dijkstras(vector<iPair> (&graph)[], int v, int n) { // n is the number of nodes, v is the starting vertex.
    vector<int> visited(n, 0);
    vector<pair<ll,ll>> dist(n); // First int is dist and second int is the prev node.
    for (int i = 0; i < n; i++) {
        dist[i].first = LLONG_MAX;
    }
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq; // Min heap priority queue
    dist[v] = make_pair(0, v);

    pq.push(make_pair(0, v));
    while (!pq.empty()) {
        int u = pq.top().second; // get minimum distance vertex
        pq.pop();
        visited[u] = 1;
        for (iPair i : graph[u]) {
            ll v = (i).first;
            ll weight = (i).second;

            if (visited[v]) continue;

            if (dist[v].first > dist[u].first + weight) {
                dist[v].first = dist[u].first + weight;
                dist[v].second = u;
                pq.push(make_pair(dist[v].first, v));
            }
        }
    }
    for (int i = 1; i < n; i++) {
        cout << dist[i].first << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    n++;
    vector<iPair> graph[n];
    ll a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        addEdge(graph, a, b, c);
    }

    dijkstras(graph, 1, n);

    return 0;
}
