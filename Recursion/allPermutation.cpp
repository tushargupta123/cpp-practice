#include<iostream>
using namespace std;

void allPermutations(string &str,int i=0,string curr=""){
    if(i==str.length()){
        cout<<curr<<endl;
        return;
    }
    allPermutations(str,i+1,str[i]+curr);
    allPermutations(str,i+1,curr+str[i]);
}

int main(){
    string str="ABC";
    allPermutations(str);
    return 0;
}