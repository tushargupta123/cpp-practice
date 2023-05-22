#include<iostream>
using namespace std;

int main(){
    string s1 = "aabcd";
    string s2 = "dscbaa";
    int count[256] = {0};
    for(char i:s1){
        count[i]++;
    }
    for(char i:s2){
        count[i]--;
    }
    for(int i=0; i<256; i++){
        if(count[i]!=0){
            cout<<char(i);
        }
    }
}