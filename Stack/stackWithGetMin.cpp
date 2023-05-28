#include<iostream>
#include<vector>
using namespace std;

struct stack{
    vector<int> s;
    int min;
    void push(int x){
        if(s.empty()){
            min = x;
            s.push_back(x);
        }else if(x<=min){
            s.push_back(2*x-min);
            min = x;
        }else{
            s.push_back(x);
        }
    }
    int pop(){
        int t= s.back();
        s.pop_back();
        int res = 0;
        if(t<=min){
            res = min;
            min = 2*min-t;
            return res;
        }else{
            return t;
        }
    }
    int getMin(){
        return min;
    } 
};

int main(){
    stack s;
    s.push(5);
    s.push(15);
    cout<<s.getMin()<<endl;
    s.push(10);
    s.push(2);
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;
    s.push(1);
    cout<<s.getMin()<<endl;
}