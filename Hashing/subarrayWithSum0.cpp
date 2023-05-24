#include<iostream>
#include<unordered_set>
using namespace std;

// concept
// x1,x2,x3,x4,x5,x6
// here if prefix sum of x1,x2,x3 is x and prefix sum of x1,x2,x3,x4,x5 is also x then subarray x4,x5 must have sum equals to 0.

int main(){
    int arr[] = {-3,4,-2,-1,5};
    int prefix_sum = 0;
    unordered_set<int> s;
    for(int i:arr){
        prefix_sum += i;
        if(prefix_sum == 0){
            cout<<"Yes";
        }
        if(s.find(prefix_sum) != s.end()){
            cout<<"Yes";
        }else{
            s.insert(prefix_sum);
        }
    }
}