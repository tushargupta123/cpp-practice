#include<iostream>
using namespace std;

int main(){
    string str = "abcd";
    string str2 = "cdab";
    str+=str;
    if(str.find(str2)!=string::npos){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}