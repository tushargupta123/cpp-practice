#include<iostream>
#include<limits.h>
using namespace std;

int* djikstraAlgo(int graph[4][4],int v){
    int* dist = new int[v];
    fill(dist,dist+v,INT_MAX);
    bool filled[v] = {false};
    dist[0] = 0;
    for(int i=0;i<v-1;i++){
        int u=-1;
        for(int j=0;j<v;j++){
            if(!filled[j] && (u==-1 || dist[u]>dist[j])){
                u=j;
            }
        }
        filled[u]= true;
        for(int j=0;j<v;j++){
            if(graph[u][j]!=0 && !filled[j]){
                dist[j] = min(dist[j],dist[u]+graph[u][j]) ;
            }
        }
    }
    return dist;
}

int main(){
    int graph[4][4] = {{0,5,10,0},
                       {5,0,3,20},
                       {10,3,0,2},
                       {0,20,2,0}};
    int n = 4;
    int *res = djikstraAlgo(graph,n);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
}