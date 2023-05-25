#include<iostream>
using namespace std;

int main(){
    string str = "abbc";
    bool visited[26];
    fill(visited,visited+26,false);
    int res = -1;
    for(int i=str.length()-1;i>=0;i--){
        if(visited[str[i]]){
            res = i;
        }else{
            visited[str[i]] = true;
        }
    }
    cout<<res;
}