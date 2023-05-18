#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;
    for(int i=0; i<7; i++){
        l.push_back(i);
    }
    auto it = l.begin();
    while(l.size() >1){
        for(int count=1; count<3; count++){
            it++;
            if(l.end()==it){
                it = l.begin();
            }
        }
        it = l.erase(it);
        if(l.end()==it){
                it = l.begin();
            }
    }
    cout<<*l.begin();
    return 0;
}
