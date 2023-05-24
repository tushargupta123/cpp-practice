#include <iostream>
using namespace std;

int main()
{
    int arr[4][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10},{ 11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};
    int top = 0;
    int right = 4;
    int bottom = 3;
    int left = 0;
    while(top <= bottom && left <= right) {
        for(int i=left; i <= right; i++){
            cout<<arr[top][i]<<" ";
        }
        top++;
        for(int i = top; i <=bottom; i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left<=right){
            for(int i = bottom; i>=top; i--){
                cout<<arr[i][left]<<" ";
            }
            left++;
        }
    }
    return 0;
}