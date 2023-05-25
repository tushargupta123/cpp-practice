#include<iostream>
using namespace std;

bool checkSub(string &str,string &str2,int i=0,string curr=""){
    if(i==str.length()){
        if(curr==str2)  return true;
        return false;
    }
    if(curr==str2){
        return true;
    }
    checkSub(str,str2,i+1,curr);
    checkSub(str,str2,i+1,curr+str[i]);
}

int main(){
    string str = "abcd";
    string str2 = "ad";
    if(checkSub(str, str2)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}