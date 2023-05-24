#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    int arr[] = {5,8,-4,-4,9,-2,2};
    int sum = 0;
    int prefix_sum = 0;
    unordered_set<int> s;
    for(int x:arr){
        prefix_sum += x;
        if(prefix_sum == sum){
            cout<<"Yes";
        }
        if(s.find(prefix_sum-sum)!=s.end()){
            cout<<"Yes";
        }
        s.insert(prefix_sum);
    }
}