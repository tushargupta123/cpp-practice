#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,10,20,30};
    int arr_2[] = {20,30,40,20};
    unordered_set<int> s;
    for(int i:arr){
        s.insert(i);
    }
    for(int i:arr_2){
        s.insert(i);
    }
    for(int i:s){
        cout<<i<<" ";
    }
}