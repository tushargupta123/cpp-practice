#include<iostream>
using namespace std;

int main(){
    string str = "geeks for geeks";
    int pos = str.find("geeks");
    while(pos!=string::npos){       // we use string::npos it means that position of element is -1 i.e it is not present in whole string
        cout<<pos<<" ";
        pos = str.find("geeks",pos+1);  // find can take two parameters (element,from where to start)
    }

}