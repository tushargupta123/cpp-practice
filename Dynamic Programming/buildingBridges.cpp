#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// we have to build bridges without cutting each other

bool myCmp(pair<int,int> a,pair<int,int> b){
    if(a.first < b.first){
        return true;
    }else if(a.first == b.first){
        if(a.second < b.second){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int ceil(int tail[], int s, int e, int x) {
    while (e >= s) {
        int m = s + (e - s) / 2;
        if (tail[m] >= x) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return s;
}

int build(vector<pair<int,int>> &arr,int n){
    sort(arr.begin(),arr.end(),myCmp);
    
    // Now use LIS for second element .
    int tail[n];
    tail[0] = arr[0].second;
    int len = 1;
    for(int i=0;i<n;i++){
        if(arr[i].second > tail[len-1]){
            tail[len] = arr[i].second;
            len++;
        }else{
            int c = ceil(tail, 0, len - 1, arr[i].second);
            tail[c] = arr[i].second;
        }
    }
    return len;
}

int main(){
    vector<pair<int,int>> arr;
    arr.push_back({1,3});
    arr.push_back({1,5});
    arr.push_back({6,2});
    arr.push_back({4,3});
    arr.push_back({2,6});
    cout<<build(arr,arr.size());
}