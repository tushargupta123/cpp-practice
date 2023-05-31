#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int>* arr, int u, int v){
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void BFS(vector<int>* adj, int start, bool visited[]){
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        cout << u << " ";
        q.pop();
        for(int x: adj[u]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int BFSdisconnected(vector<int>* adj, int vertex){
    bool visited[vertex];
    int count = 0;
    for(int i=0; i<vertex; i++){
        visited[i] = false;
    }
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            BFS(adj, i, visited);
            count++;
        }
    }
    return count;
}

void printGraph(vector<int> arr[],int v){
    for(int i=0;i<v;i++){
        for(int x:arr[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
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
    cout << endl << BFSdisconnected(adj, vertex);
    delete[] adj;
    return 0;
}
