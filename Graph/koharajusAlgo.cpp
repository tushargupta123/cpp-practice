#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// algortihm
// order the vertices in decreasing order of their complete time
// reverse all edges
// do dfs of the reversed graph int the order obtained in step 1. for each vertex print all reachable vertices as one strongly connected component

void addEdge(vector<int>* adj,int u,int v,vector<int>* adjRev){
    adj[u].push_back(v);
    adjRev[v].push_back(u);
}

void DFSRec(vector<int>* adj,int u,stack<int> &s,bool visited[]){
    visited[u] = true;
    for(int x:adj[u]){
        if(!visited[x]){
            DFSRec(adj,x,s,visited);
        }
    s.push(x);
    }
}

void printStronglyConnectedElements(vector<int>* adj,int u,bool visited[],int vertex){
    visited[u] = true;
    cout<<u<<" ";
    for(int i = 0; i< vertex;i++){
        if(!visited[i]){
            printStronglyConnectedComponent(adj,i,visited,vertex);
        }
    }
}

void koharajusAlgo(vector<int>* adj,int vertex,vector<int>* adjRev){
    stack<int> s;
    int* res = new int[vertex];
    bool visited[vertex] = {false};
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            DFSRec(adj,i,s,visited);
        }
    }
    for(int i=0;i<vertex;i++){
        res[i] = s.top();
        s.pop();
        visited[i] = false;
    }
    for(int i=0;i<vertex;i++){
        if(!visited[res[i]]){
            printStronglyConnectedComponent(adjRev,res[i],visited,vertex);
        }
    }
}

int main(){
    int vertex = 5;
    vector<int> adj[vertex];
    vector<int> adjRev[vertex];
    addEdge(adj,0,1,adjRev);
    addEdge(adj,1,2,adjRev);
    addEdge(adj,2,0,adjRev);
    addEdge(adj,1,3,adjRev);
    addEdge(adj,3,4,adjRev);
    koharajusAlgo(adj,vertex,adjRev);
}