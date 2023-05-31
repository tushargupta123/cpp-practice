#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int>* arr, int u, int v){
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void DFS(vector<int>* adj, int start, bool visited[]){
    visited[start] = true;
    cout<<start<<" ";
    for(int u:adj[start]){
        if(!visited[u]){
            DFS(adj,u,visited);
        }
    }
}

int DFSdisconnected(vector<int>* adj, int vertex){
    bool visited[vertex];
    int count = 0;
    for(int i=0; i<vertex; i++){
        visited[i] = false;
    }
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            DFS(adj, i, visited);
            count++;
        }
    }
    return count;
}

int main(){
    int vertex = 8;
    vector<int>* adj = new vector<int>[vertex];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 7);
    addEdge(adj, 5, 7);
    cout << endl << DFSdisconnected(adj, vertex);
    delete[] adj;
    return 0;
}
