#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,30,30,5};
    int arr_2[] = {20,5,20,30};
    unordered_set<int> us;
    for(int x:arr){
        us.insert(x);
    }
    for(int x:arr_2){
        if(us.find(x)!=us.end()){
            cout<<x<<" ";
            us.erase(x);
        }
    } 
}