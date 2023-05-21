#include<iostream>
using namespace std;

bool check(string &str,int start,int end){
    if(start>end){
        return true;
    }else{
        if(str[start]==str[end]){
            check(str,start+1,end-1);
        }else{
            return false;
        }
    }
}

int main(){
    string str = "abccba";
    int n = str.length();
    if(check(str,0,n-1))
        cout<<"it is palindrome"<<endl;
    else
        cout<<"it is not palindrome"<<endl;
    return 0;
}