// it is somewhat same as the segment tree but hare we use index in binary form to store the value and their sum
// in segment tree time complexity of every operation is O(4 log n) whaereas in BIT it is O(log n) 
// and same is space it is O(4 n) in  segment tree and O(n) in BIT .

 
#include <iostream> 

using namespace std; 

 
int getSum(int BITree[], int index) 
{
	int sum = 0; 

	 
	index = index + 1; // bcs in BIT we have null at 0 index

	 
	while (index>0) 
	{ 
		
		sum += BITree[index]; // we add value at every parent node

		
		index -= index & (-index); // formula for getting parent node in BIT
	} 
	return sum; 
} 

void updateBIT(int BITree[], int n, int index, int val) 
{ 
    
    index = index + 1; 
  
     
    while (index <= n) 
    { 
   
    BITree[index] += val;                   // we add diff to every child node
  
   
    index += index & (-index);              // formula for getting child node in BIT
    } 
}
 
int *constructBITree(int arr[], int n) 
{ 
	
	int *BITree = new int[n+1]; 
	for (int i=1; i<=n; i++) 
		BITree[i] = 0; 

	 
	for (int i=0; i<n; i++) 
		updateBIT(BITree, n, i, arr[i]); 

	

	return BITree; 
} 


 
int main() 
{ 
	int freq[] = {10, 20, 30, 40, 50, 60, 70, 80, 90}; 
	int n = sizeof(freq)/sizeof(freq[0]); 
	int *BITree = constructBITree(freq, n); 
	cout << "Sum of elements in arr[0..5] is "
		<< getSum(BITree, 5); 

	
	
	return 0; 
} 
