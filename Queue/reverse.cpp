#include<iostream>
#include<queue>
using namespace std;

void reverse(queue<int> &q){
    if(q.size() == 0){
        return;
    }
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

//  we just store front and reverse the remaining queue and then push it so now it will go on rear we do it recursively .

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    reverse(q);
    cout<<q.front();
}