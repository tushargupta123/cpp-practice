#include<iostream>
#include<limits.h>
using namespace std;

int primsAlgo(int graph[4][4],int v){
    int dist[v],res=0;
    fill(dist,dist+v,INT_MAX);
    dist[0] = 0;
    bool mSet[v] = {false};
    for(int i=0;i<v;i++){
        int u = -1;
        for(int j=0;j<v;j++){
            if(!mSet[j] && (u==-1 || dist[u]>dist[j])){
                u=j;
            }
        }
        mSet[u] = true;
        res = res + dist[u];
        for(int j=0;j<v;j++){
            if(graph[u][j]!=0 && !mSet[j]){
                dist[j] = min(dist[j],graph[u][j]);
            }
        }
    }
    return res;
}

int main(){
    int graph[4][4] = {{0,5,10,0},
                       {5,0,8,15},
                       {10,8,0,20},
                       {0,15,20,0}};
    cout<<primsAlgo(graph,4);
}