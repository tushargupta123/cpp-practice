#include<iostream>
#include<map>
using namespace std;

int main(){
    int arr[] = {2,8,10,5,8};
    map<int,int> mp;
    for(int x = 0; x<5; x++){
        mp[arr[x]] = mp[arr[x]] + 1;
    }
    int cum_freq = 0;
    for(auto it = mp.rbegin(); it!=mp.rend(); it++){
        int freq = it->second;
        it->second = cum_freq;
        cum_freq += freq;
    }
    for(auto x: mp){
        cout<<x.first<<" -> "<<x.second<<endl;
    }
}