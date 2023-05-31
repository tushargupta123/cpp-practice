#include<iostream>
#include<set>
using namespace std;

int main(){
    int arr[] = {2,8,30,15,7,15};
    set<int> s;
    for(int i=0; i<6; i++){
        auto it = s.lower_bound(arr[i]);        // lower_bound returns the element if it present else return element greater than given element
        if(it != s.end()){
            cout<<(*it)<<" ";
        }else{
            cout<<-1<<" ";
        }
        s.insert(arr[i]);
    }
}