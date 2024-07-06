#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int n = 15;
vector<int> visited(n,0);

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void bfs(vector<int> G[], int v){
    queue<int> queue;
    vector<int> visited(n,0);
    queue.push(v);
    while(!queue.empty()){
        v= queue.front();
        queue.pop();
        if(!visited[v]){
            cout << v << " ";
            visited[v] = 1;
            for(auto it:G[v]){
                if(!visited[it]){
                    queue.push(it);
                }
            }
        }
    }
}

void dfs_iter(vector<int> G[], int v){
    vector<int> stack;
    vector<int> visited(n,0);
    stack.push_back(v);
    while(!stack.empty()){
        v = stack.back();
        stack.pop_back();
        if(!visited[v]){
            visited[v] = 1;
            cout << v << " ";
            for(auto it:G[v]){
                if(!visited[it])
                    stack.push_back(it);
            }
        }
    }
}

void dfs(vector<int> G[], int v){
    cout << v << " ";
    visited[v] = 1;
    for(int i:G[v]){
        if(!visited[i]){
            dfs(G,i);
        }
    }
}

int main(){
    int roll;
    vector<int> graph[n];
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 2, 10);
    addEdge(graph, 3, 7);
    addEdge(graph, 3, 8);
    addEdge(graph, 4, 9);
    addEdge(graph, 5, 10);
    addEdge(graph, 6, 11);
    addEdge(graph, 6, 12);
    addEdge(graph, 9, 13);
    addEdge(graph, 9, 14);

    roll = 1;

    bfs(graph,roll);


    return 0;
}
