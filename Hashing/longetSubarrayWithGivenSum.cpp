#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int arr[] = {8,3,1,5,-6,6,2,2};
    int sum = 4;
    int prefix_sum = 0;
    int res = 0;
    unordered_map<int, int> m;
    for(int i=0;i<8;i++){
        prefix_sum += arr[i];
        if(prefix_sum == sum){
            res = i+1;
        }
        m.insert({prefix_sum,i});
        if(m.find(prefix_sum-sum) != m.end()){
            res = max(res,i-m[prefix_sum-sum]);
        }
    }
    cout<<res;
}