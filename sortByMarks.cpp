#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

bool myCmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

void sortedByMarks(int roll[],int marks[],int n){
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        v.push_back({roll[i], marks[i]});
    }
    sort(v.begin(), v.end(),myCmp);
    for(int i=0; i<n; i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}

int main(){
    int roll[] = {1,2,3,4,5};
    int marks[] = {20,40,10,90,30};
    sortedByMarks(roll,marks,5);
    return 0;
}