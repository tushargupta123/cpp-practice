#include<iostream>
using namespace std;

bool ratMaze(int maze[4][4],int n,int i=0,int j=0){
    if(i==n-1 && j==n-1){
        return true;
    }
    if(i<n && j<n && maze[i][j]==1){
        if(ratMaze(maze,n,i+1,j)){
            return true;
        }else if(ratMaze(maze,n,i,j+1)){
            return true;
        }
    }
    return false;
}

int main(){
    int maze[4][4] = {{1,0,0,0},
                      {1,1,0,0},
                      {0,1,0,0},
                      {1,1,1,1}};
    cout<<ratMaze(maze,4);
    return 0;
}