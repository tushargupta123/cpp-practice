#include<iostream>
using namespace std;

int main(){
    int arr1[] = {10,20,30};
    int arr2[] = {5,15,25,35,45};
    int begin = 0,end=3;
    while(begin<=end){
        int i1 = (begin+end)/2;
        int i2 = ((3+5+1)/2) - i1;
        int max1 = arr1[i1-1];
        int min1 = arr1[i1];
        int max2 = arr2[i2-1];
        int min2 = arr2[i2];
        if(min1 >= max2 && min2 >= max1){
            if(((3+5)%2)==0){
                cout<<(double)((max(max1,max2)+min(min1,min2))/2);
                break;
            }else{
                cout<<(double)(max(max1,max2));
                break;
            }
        }else if(max1>min2){
            end = i1-1;
        }else{
            begin = i1+1;
        }
    }
}