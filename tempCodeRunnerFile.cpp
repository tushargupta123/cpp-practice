#include<iostream>
using namespace std;

    int reverse(int x) {
        bool isNeg = false;
        string res = to_string(x);
        int i=0;
        if(x<0){
            isNeg = true;
            x = 0-x;
        }
        while(x>0){
            int j = x%10;
            res[i] = j + '0';
            x = x/10;
            i++;
        cout<<res<<endl;
        }
        int result = 0;
        for (char c : res) {
            result = result * 10 + (c - '0');
    }
        if(isNeg){
            result = 0 - result;
        }
        return result;
    }

int main(){
    cout<<reverse(123);
}