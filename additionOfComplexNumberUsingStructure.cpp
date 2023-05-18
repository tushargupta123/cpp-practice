#include<iostream>
using namespace std;

struct complexNumber {
    int real;
    int imaginary;
};

int main(){
    complexNumber c1 = {2,4};
    complexNumber c2 = {3,5};
    cout<<"addition of this is :"<<c1.real+c2.real<<"+"<<c1.imaginary+c2.imaginary<<"i";
}