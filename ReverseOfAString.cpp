#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str = "tushar";
    stack<char> s;
    for(char c:str){
        s.push(c);
    }
    for(int i=0; i<str.length(); i++){
        cout<<s.top();
        s.pop();
    }
}