#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int arr[] = {10,20,10,10,30,40};
    unordered_map<int,int> m;
    // k = 4  -> 6-k+1 => 3 windows
    for(int i=0; i<4;i++){
        m[arr[i]]++;
    }
    cout<<m.size()<<endl;
    for(int i = 4; i < 6; i++){
        m[arr[i-4]]--;
        if(m[arr[i-4]] == 0){
            m.erase(arr[i-4]);
        }
        m[arr[i]]++;
        cout<<m.size()<<endl;
    }
}