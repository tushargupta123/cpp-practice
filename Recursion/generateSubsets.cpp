#include<iostream>
using namespace std;

void printSubsets(string &str,string curr="",int i=0){
    if(i==str.length()){
        cout<<curr<<endl;
        return;
    }
    printSubsets(str,curr,i+1);
    printSubsets(str,curr+str[i],i+1);
}

int main(){
    string str = "abc";
    printSubsets(str,"",0);
    return 0;
}