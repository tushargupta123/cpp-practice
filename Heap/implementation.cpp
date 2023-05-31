#include<iostream>
using namespace std;

struct MinHeap{
    int *arr;
    int size;
    int cap;
    MinHeap(int c){
        arr = new int[c];
        size =0;
        cap = c;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    void insert(int x){
        if(size == cap) return;
        size++;
        arr[size-1] = x;
        for(int i=size-1; i!=0 && arr[parent(i)] > arr[i];){
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
    }
};

int size = 7;

//  MIN HEAPIFY

void minHeapify(int i,int arr[]){
    int lt = 2*i+1,rt =2*i+2;
    int smallest = i;
    if(lt<size && arr[lt]<arr[i]){
        smallest = lt;
    }
    if(rt<size && arr[rt]<arr[smallest]){
        smallest = rt;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        minHeapify(smallest,arr);
    }
}

// Extract min

int extractMin(int arr[]){
    swap(arr[0],arr[size-1]);
    size--;
    minHeapify(0,arr);
    return arr[size];
}

// Decrease key            => we are given a value and a index at which we have to update that value.after all that we have to again form it into heap

void decreaseKey(int i,int k,int arr[]){
    arr[i] = k;
    while(i!=0 && arr[i]<arr[(i-1)/2]){
        swap(arr[(i-1)/2],arr[i]);
        i = (i-1)/2;
    }
}

// Delete index

void deleteIndex(int i,int arr[]){
    swap(arr[i],arr[size-1]);
    size--;
    minHeapify(i,arr);
}

// Build heap           => time complexity is O(n)   however it looks likes O(n log n)

void buildHeap(int arr[]){
    for(int i=(size-2)/2;i>=0;i--){          // we consider i startinf from parent of last leaf node. index of last leaf node = size-1 hence parent = ((size-1)-1)/2
        minHeapify(i,arr);
    }
}

int main(){
    int arr[] = {10,20,2,5,30,1,22};
    buildHeap(arr);
    for(int x:arr){
        cout<<x<<" ";
    }
}