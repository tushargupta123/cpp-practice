#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int>* adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool detectCycle(vector<int>* adj,int start,int vertex,int parent = -1){
    bool visited[vertex];
    for(int i=0;i<vertex;i++){
        visited[i] = false;
    }
    visited[start] = true;
    for(int x:adj[start]){
        if(!visited[x]){
            if(detectCycle(adj,x,vertex,start)){
                return true;
            }
        }else if(x != parent){
            return true;
        }
    }
    return false;
}

int main(){
    int vertex = 4;
    vector<int> adj[vertex];
    addEdge(adj,0,1);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,3,2);
    cout<<detectCycle(adj,0,vertex);
}