#include<iostream>
using namespace std;

int main(){
    string str = "abcdba";
    int start=0,end=str.length()-1;
    while(start<end){
        if(str[start] == str[end]){
            start++;
            end--;
        }else{
            cout<<"Not a palindrome";
            return 0;
        }
    }
    cout<<"It is a palindrome";
    return 0;
}