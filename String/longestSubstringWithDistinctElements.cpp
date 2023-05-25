#include<iostream>
using namespace std;

int main(){
    string str = "abcabdda";
    int n = str.length();
    int count[256];
    int res = 0;
    int j = 0;
    fill(count,count+256,-1);
    for(int i=1;i<n;i++){
        j= max(j,count[str[i]]+1);
        int maxEnd = i-j+1;
        res = max(res,maxEnd);
        count[str[1]] = i;
    }
    cout<<res;
}