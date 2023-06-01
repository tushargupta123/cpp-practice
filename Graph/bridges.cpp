#include<iostream>
#include<vector>
using namespace std;

void bridgeUtil(vector<int>* adj,int u,int& time,int parent,bool visited[],int disc[],int low[]){
    visited[u] = true;
    disc[u] = low[u] = ++time;
    for(auto v:adj[u]){
        if(!visited[v]){
            bridgeUtil(adj,v,time,u,visited,disc,low);
            low[u] = min(low[v],low[u]);
            if(low[v]>low[u]){
                cout<<u<<"-"<<v<<endl;
            }
        }else if (v != parent)
			low[u] = min(low[u], disc[v]);
    }
}

void bridge(vector<int>* adj,int v){
    bool visited[v] = {false};
    int disc[v] = {0};
    int low[v];
    int parent = -1,time =0;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bridgeUtil(adj,i,time,parent,visited,disc,low);
        }
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 0);
	addEdge(adj, 1, 3);
	addEdge(adj, 3, 4);
	bridge(adj, V);

	return 0;
}