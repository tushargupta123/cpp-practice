#include<iostream>
#include<vector>
using namespace std;

void print(int **arr,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
}

void print_vect(vector<vector<int>> &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
}

int main(){
    // dynamically creating 2d array of size mXn.
    int n =2 , m=3;
    int *arr[m];
    for(int i=0;i<m;i++){
        arr[i] = new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = i+j;
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;

    // creating 2d array using vector where we can also change rows and columns dynamically
    vector<vector<int>> ary;
    for(int i=0;i<m;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            v.push_back(10);
        }
        ary.push_back(v);
    }
    print_vect(ary);
    // to pass this we dont need to pass rows and columns also as we can get size of vector

    // while creating 2d array generally we can omit only first bracket ,i.e,row can be omitted and it will be assumed by compiler
    int arr_2[][2] = {{10,20},{20,20},{30,40}};
    // here value of row will be 3


    // creating 2d array using double pointer
    int **arr_3;
    arr_3 = new int*[m];
    for(int i=0; i<m; i++){
        arr_3[i] = new int[n];
        for(int j=0; j<n; j++){
            arr_3[i][j] = i; 
        }
    }
    print(arr_3,m,n);
    // we can pass array created using double pointer very easily with variable m and n.
}