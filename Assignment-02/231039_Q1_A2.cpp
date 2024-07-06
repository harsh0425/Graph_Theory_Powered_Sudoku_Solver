#include <bits/stdc++.h>
#include <queue>

using namespace std;

#define ll long long
#define vi vector<int>
#define iPair pair<ll,ll>
#define For(i,n) for(int i=0;i<n;i++)
#define aFor(i,a,n) for(int i = a;i<n;i++)

map<int,vector<pair<ll,ll>>> mp;


void addEdge(vector<iPair> (&graph)[], int u, int v,int w) {
    graph[u].push_back(make_pair(v,w));
    graph[v].push_back(make_pair(u,w));
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
    mp[v] = dist;
}

void shortest_dist(vector<iPair> (&graph)[],int start,int n){
    if(!(mp.find(start)!=mp.end())){
        dijkstras(graph,start,n);
    }

    vector<pair<ll,ll>> vec = mp[start];
    cout << "Vertex \t\t\t Distance \t\t\t Path" << endl;
    for(int i =1 ;i<n;i++){
        int dist = vec[i].first, prev_node = vec[i].second, len = 1;
        
        printf("%d \t\t\t %d \t\t\t ",i,dist);
        
        vector<int> path = {prev_node}; 
        while(prev_node != start){
            prev_node = vec[prev_node].second;
            path.push_back(prev_node);
            len++;
        }
        for(int i = len-1; i >=0;i--)
            cout << path[i] << " ";
        cout << endl;
    }
}

int main(){
    int n = 7;
    vector<iPair> graph[n];

    addEdge(graph,1,2,2);
    addEdge(graph,1,4,8);
    addEdge(graph,2,4,5);
    addEdge(graph,2,5,6);
    addEdge(graph,4,5,3);
    addEdge(graph,4,6,2);
    addEdge(graph,5,6,1);
    addEdge(graph,3,5,9);
    addEdge(graph,3,6,3);

    shortest_dist(graph, 1,n);
    return 0;
}
