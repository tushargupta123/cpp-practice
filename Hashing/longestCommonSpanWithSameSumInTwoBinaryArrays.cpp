#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int arr_1[] = {0,1,0,0,0,0};
    int arr_2[] = {1,0,1,0,0,1};
    int arr[6];
    for(int i=0;i<6;i++){
        arr[i] = arr_1[i]-arr_2[i];
    }
    int prefix_sum = 0;
    int res = 0;
    unordered_map<int, int> m;
    for(int i = 0; i < 6;i++){
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