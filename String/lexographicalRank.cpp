#include<iostream>
using namespace std;

int fact(int n){
    if(n==1)    return 1;
    return (n*fact(n-1));
}

int main(){
    string str = "string";
    // My implementation

    // int less = 0;
    // int res = 0;
    // for(int i=0;i<str.length()-1;i++){
    //     for(int j=i+1;j<str.length();j++){
    //         if(str[i]>str[j]){
    //             less++;
    //         }
    //     }
    //     res += less*fact(str.length()-i-1);
    //     less = 0;
    // }
    // cout<<res+1;

    int res = 1;
    int n = str.length();
    int mul = fact(n);
    int arr[256] = {0};
    for(int i=0; i<n; i++){
        arr[str[i]]++;
    }
    for(int i=1; i<256; i++){
        arr[i] += arr[i-1];         // cummilative sum to know how many characters are greater than that character
    }
    for(int i=0; i<n-1; i++){
        mul = mul/(n-i);
        res += (arr[str[i]-1])*mul;
        for(int j=str[i];j<256;j++){
            arr[j]--;
        }
    }
    cout<<res;
}