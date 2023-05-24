#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int arr[] = {1,0,1,1,1,0,0};
    int prefix_sum = 0;
    int res = 0;
    unordered_map<int, int> m;
    for(int i = 0; i < 7;i++){
        if(arr[i] == 0){
            arr[i] = -1;
        }
        prefix_sum += arr[i];
        if(prefix_sum == 0){
            res = max(res,i+1);
        }
        m.insert({prefix_sum,i});
        if(m.find(prefix_sum) != m.end()){
            res = max(res,i-m[prefix_sum]);
        }
    }
    cout<<res;
}