#include<iostream>
using namespace std;

// char will always will automatically typecasted to int but we have to typecast manually from int to char

int main(){
    string str = "geeksforgeeks";
    int count[26] = {0};
    for(char x:str){
        count[x-'a']++;
    }
    for(int i=0; i< 26; i++){
        if(count[i]>0){
            cout<<(char)(i+'a')<<" "<<count[i]<<endl;
        }
    }
}