#include<iostream>
using namespace std;

int main(){
    int petrol[] = {50,10,60,100};
    int dist[] = {30,20,100,10};
    int prev_pet = 0,curr_pet=0, start=0;
    for(int i=0;i<4;i++){
        curr_pet += petrol[i]-dist[i];      // it assumes that we reached next petrol pump.
        if(curr_pet < 0){
            start = i+1;
            prev_pet = curr_pet;
            curr_pet = 0;
        }
    }
    int res = ((curr_pet + prev_pet) >=0 ? (start+1) : -1);
    // idea we use is if we are not able to reach next petrol pump with previous combination then we will never be able to do that anyway if we start from any
    // other point also so we start from next petrol pump directly . and at last as we have to complete the tour so we check that whether with the left petrol
    // we can travel the distance from arr[0] to arr[i]. bcs here we consider to travel only pertol pumps ahead not circular .
    cout<<res;
}