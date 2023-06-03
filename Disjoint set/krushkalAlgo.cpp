#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
    int src,dest,wt;
    Edge(int s,int d,int w){
        src =s;
        dest =d;
        wt =w;
    }
};

bool MyCmp(Edge* e1, Edge* e2) {
    return e1->wt < e2->wt;
}

void initialize(int n, int parent[], int rank[])
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findSet(int x, int parent[])
{
    if (parent[x] == x)
    {
        return x;
    }
    parent[x] = findSet(parent[x],parent);
    return parent[x];                                   
}
void unionByRank(int x, int y, int parent[], int rank[])      
{
    int x_rep = findSet(x, parent);
    int y_rep = findSet(y, parent);
    if (x_rep == y_rep)
        return;
    if(rank[x_rep] > rank[y_rep]){
        parent[y_rep] = x_rep;
    }else if(rank[x_rep] < rank[y_rep]){
        parent[x_rep] = y_rep;
    }else{
        parent[y_rep] = x_rep;
        rank[x_rep]++;
    }
}

int kruskal(vector<Edge *> &arr,int parent[],int rank[],int v){
    sort(arr.begin(),arr.end(),MyCmp);
    int res = 0;
    for(int i=0,s=0;s<v-1;i++){
        Edge* e = arr[i];
        int x = findSet(e->src,parent);
        int y = findSet(e->dest,parent);
        if(x!=y){
            res += e->wt;
            unionByRank(x,y,parent,rank);
            s++;
        }
    }
    return res;
}

int main(){
    vector<Edge *> arr;
    arr.push_back(new Edge(0,1,10));
    arr.push_back(new Edge(0,2,8));
    arr.push_back(new Edge(1,2,5));
    arr.push_back(new Edge(1,3,3));
    arr.push_back(new Edge(2,3,4));
    arr.push_back(new Edge(2,4,12));
    arr.push_back(new Edge(3,4,15));
    int v = 5;
    int parent[v],rank[v];
    initialize(v,parent,rank);
    cout<<kruskal(arr,parent,rank,v);
}