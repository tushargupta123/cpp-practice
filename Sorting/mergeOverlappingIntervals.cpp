#include<iostream>
#include<algorithm>
using namespace std;

struct arr{
    int start;
    int end;
};

bool myCmp(arr a, arr b) {
    return (a.start < b.start);
}

int main(){
    arr a[] = {{7,9},{6,10},{4,5},{1,3},{2,4}};
    sort(a,a+5,myCmp);
    int res=0;
    for(int i=0;i<5;i++){
        if(a[res].end>=a[i].start){
            a[res].start = min(a[res].start,a[i].start);
            a[res].end = max(a[res].end,a[i].end);
        }else{
            res++;
            a[res]=a[i];
        }
    }
    for(int x=0;x<=res;x++){
        cout<<a[x].start<<" "<<a[x].end<<endl;
    }
}