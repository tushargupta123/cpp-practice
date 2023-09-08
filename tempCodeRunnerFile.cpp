#include<iostream>
using namespace std;

int main(){
    string res = "";
    int n = 8;
        while(n>0){
            res=to_string(n%2)+res;
            n/=2;
        }
        cout<< res;
}