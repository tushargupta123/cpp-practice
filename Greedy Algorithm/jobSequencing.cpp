#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myCmp(pair<int,int> a, pair<int,int> b){
    return (a.second > b.second );
}

int main(){
    vector<pair<int,int>> job;
    int res =0;
    job.push_back({2,10});
    job.push_back({1,50});
    job.push_back({2,100});
    job.push_back({1,30});
    job.push_back({3,30});
    sort(job.begin(),job.end(),myCmp);
    bool slot[5] = {false};
    for(int i=0; i<5;i++){
        for(int j=min(5,job[i].first)-1; j>=0; j--){
            if(!slot[j]){
                slot[j] = true;
                res += job[i].second;
                break;
            }
        }
    }
    cout<<res;
}