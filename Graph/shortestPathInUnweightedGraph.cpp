#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

void addEdge(vector<int>* adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int shortestPath(vector<int>* adj,int source,int vertex){
    bool visited[vertex];
    int dist[vertex];
    for(int i=0;i<vertex;i++){
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    queue<int> q;
    visited[source] = true;
    q.push(source);
    dist[source] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int x:adj[u]){
            if(!visited[x]){
                dist[x] = dist[u] + 1;
                q.push(x);
                visited[x] = true;
            }
        }
    }
    return dist[vertex-1];
}

int main(){
    int vertex = 4;
    vector<int> adj[vertex];
    addEdge(adj,0,1);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,3,2);
    cout<<shortestPath(adj,0,vertex);
    return 0;
}