#include <iostream>
#include <queue>
#include <utility>
#include <climits>

using namespace std;
typedef pair<int, int> pnn;
const int MAX_NODES = 100;

//implement the function of dijkstra's algorithm

void dijkstra(int n, int edge[][2], int weight[], int e, int initial, int distance[])
{
for(int i=0;i<n;i++)
    {distance[i]=INT_MAX;}

distance[initial]=0;
pnn adj[MAX_NODES][MAX_NODES];
int size_nodes[MAX_NODES]={0};

for (int i=0;i<e;i++){
    int a=edge[i][0];
    int b=edge[i][1];
    int c_weights=weight[i];
    adj[a][size_nodes[a]++] = {b, c_weights};
}

priority_queue<pnn, vector<pnn>, greater<pnn>> priority_queue;
priority_queue.push({0, initial});


bool visited[MAX_NODES] = {false};
while (!priority_queue.empty()) {
        int current_distance = priority_queue.top().first;
        int current_node = priority_queue.top().second;
        priority_queue.pop();

        // Skip processing if the node is already visited
        if (visited[current_node]) {
            continue;
        }

        // Mark the node as visited
        visited[current_node] = true;

        // Update distances for neighbors
        for (int i = 0; i < size_nodes[current_node];i++) {
            int next_node = adj[current_node][i].first;
            int weight = adj[current_node][i].second;
            int distanc = current_distance + weight;

            // Only consider this new path if it's better
            if (distanc < distance[next_node]) {
                distance[next_node] = distanc;
                priority_queue.push({distanc, next_node});
            }
        }
    }


}



int main(){
int n=6;
int e=6;
int edge[6][2]={{0,1},{1,2},{1,3},{2,4},{3,4},{4,5}};
int weight[6]={17,6,3,8,7,11};
int initial=0;
int distance[MAX_NODES];
dijkstra(n,edge,weight,e,0,distance);
cout << "Shortest distances from node " << initial << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": " << distance[i] << "\n";
    }

return 0;
}
