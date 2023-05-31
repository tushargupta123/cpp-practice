#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int>* adj,int u,int v){
    adj[u].push_back(v);
}

bool DFSRec(vector<int>* adj,int start,bool visited[],bool recSt[]){
    visited[start] = true;
    recSt[start] = true;
    for(int x:adj[start]){
        if(!visited[x] && DFSRec(adj,x,visited,recSt)==true){
            return true;
        }else if(recSt[x]){
            return true;
        }
    }
    recSt[start] = false;
    return false;
}

bool detectCycle(vector<int>* adj,int vertex){
    bool visited[vertex];
    bool recSt[vertex];
    for(int i=0;i<vertex;i++){
        visited[i] = false;
        recSt[i] = false;
    }
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            if(DFSRec(adj,i,visited,recSt)==true){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int vertex = 4;
    vector<int> adj[vertex];
    addEdge(adj,0,1);
    addEdge(adj,2,1);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,3);
    cout<<detectCycle(adj,vertex);
}