#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {30,40,10,80,5,12,70};
    int max_value=0;
    int n = sizeof(arr)/sizeof(int);
    int k =4;
    for(int x:arr){
        if(x>max_value){
            max_value=x;
        }
    }
    max_value++;
    vector<int> bkt[4];
    // fill bucket 
    for(int i=0;i<n;i++){
        int bi = (k*arr[i])/max_value;
        bkt[bi].push_back(arr[i]);
    }
    // sort bucket
    for(int i=0;i<k;i++){
        sort(bkt[i].begin(),bkt[i].end());
    }
    int index = 0;
    // join bucket
    for(int i=0;i<k;i++){
        for(int j=0;j<bkt[i].size();j++){
            arr[index++] = bkt[i][j];
        }
    }
    for(int x:arr){
        cout<<x<<" ";
    }
}