// find(x) => returns a representative of that set
// so if we have to find whether two elements belong to same set or not then we have to find(x) == find(y) bcs they will return same value ,i.e., their set representative

// union(x,y) => combine whole set of a & b

#include <iostream>
using namespace std;

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
    parent[x] = findSet(parent[x]);                     // path compression   => here we find parent and then set it also as parent of that only
    return parent[x];                                   // this helps in reducing length of tree again and parent will remain same.
    // return findSet(parent[x], parent);                      // normal
}

void unionSet(int x, int y, int parent[])                   // here we append any node to any other node
{
    int x_rep = findSet(x, parent);
    int y_rep = findSet(y, parent);
    if (x_rep == y_rep)
        return;
    parent[y_rep] = x_rep;
}

void unionByRank(int x, int y, int parent[], int rank[])            // here we append new child to parent whose height is higher , this make length of tree shorter
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

int main()
{
    int n = 5;
    int parent[n];
    int rank[n];
    initialize(n, parent,rank);
    unionByRank(1, 4, parent,rank);
    unionByRank(1, 2, parent,rank);
    unionByRank(2, 3, parent,rank);
    cout << findSet(3, parent);
}