#include<iostream>
#include<iomanip>
using namespace std;

struct student {
    int roll;
    string name;
    int age;
};

int main(){
    cout<<2.1e2<<"\n";
    double x= 1.2e5,y=1.234567;
    cout<<fixed<<setprecision(3)<<x<<"\n"<<y;

    // sum of n natural numbers
    // int n,sum=0;
    // cout<<"\n enter the number n";
    // cin>>n;
    // for(int i=n; i>0; i--){
    //     sum+=i;
    // }
    // cout<<sum;

    // loop traversal
    int arr[] = {20,10,30};
    for(int x:arr){
        cout<<"\n"<<x;
    }

    // get full line as input
    // string str;
    // cout<<"\n Enter your full name";
    // cin>>str;   // this would give me only Tushar if i enter Tushar gupta also
    // cout<<str;
    // getline(cin, str);
    // cout<<str;

    // ways of iterating string
    string str = "tushar";
    for(char x:str){
        cout<<x;
    }
    cout<<endl;
    for(auto i=str.begin(); i!=str.end();i++){
        cout<<(*i);
    }
    cout<<endl;

    student s1 = {1,"tushar",20};
    student s2 = {2,"akg",22};

    cout<<"\n"<<s1.name<<endl;

    // pointer to struct
    student *ptr = &s1;
    cout<<ptr->age<<endl;
    ptr->age = 21;
    cout<<ptr->age<<endl;

    return 0;
}