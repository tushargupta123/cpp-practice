#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<string> q;
    q.push("5");
    q.push("6");
    for(int i = 0; i <10;i++){
        string current = q.front();
        cout<<current<<" ";
        q.push(current+'5'); 
        q.push(current+'6'); 
        q.pop();
    } 
}
