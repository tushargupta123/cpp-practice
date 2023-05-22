#include<iostream>
using namespace std;

int main() {
    int arr[] = {3,4,3,4,8,4,4,32,7,7};
    int res1=0, res2 =0,res =0;
    for(int i:arr){
        res = res ^ i;
    }
    int last_set_bit = res & ~(res-1);
    for(int i=0; i<10; i++){
        if((arr[i] & last_set_bit) != 0){
            res1 = arr[i] ^res1;
        }else{
            res2 = res2 ^ arr[i];
        }
    }
    cout<<res1<<" "<<res2<<endl;
}