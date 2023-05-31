#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Kahn's algorithm
// topological sort       -> dependency based sort if a node whose all nodes on which it was depending is completed then it will get completed
// detection of cycle

void addEdge(vector<int>* adj,int u,int v,int inIndex[]){
    adj[u].push_back(v);
    inIndex[v]++;
}

void topologicalSort(vector<int>* adj,int inIndex[],int vertex){
    queue<int> q;
    for(int i=0;i<vertex;i++){
        if(inIndex[i]==0){
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty()){
        count++;
        int u = q.front();
        q.pop();
        inIndex[u] = -1;
        cout<<u<<" ";
        for(int x:adj[u]){
            inIndex[x]--;
            if(inIndex[x]==0){
            q.push(x);
        }
        }
    }
    if(count!=vertex){
        cout<<"Cycle";
    }
}

int main(){
    int vertex = 5;
    vector<int> adj[vertex];
    int inIndex[vertex] = {0};
    addEdge(adj,0,2,inIndex);
    addEdge(adj,0,3,inIndex);
    addEdge(adj,2,3,inIndex);
    addEdge(adj,1,3,inIndex);
    addEdge(adj,1,4,inIndex);
    addEdge(adj,3,0,inIndex);
    topologicalSort(adj,inIndex,vertex);
}