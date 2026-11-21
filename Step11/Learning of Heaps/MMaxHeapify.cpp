#include<iostream>
#include<vector>
using namespace std; 

void heapify(vector<int> &arr, int i, int n){
    int largest = i; 
    int left = 2*i+1; 
    int right = 2*i+2; 
    if(left < n && arr[left] > arr[largest])
        largest = left; 
    if(right < n && arr[right] > arr[largest])
        largest = right;
        
    // If largest is not root
    // Swap and contuinue heapifying 

    if(largest != i){
        swap(arr[largest], arr[i]); 
        //Recursively Heapify
        heapify(arr, largest, n); 
    }
}

int main(){
    vector<int> arr = {10, 5, 15, 2, 20, 30}; 
    cout << "Original Array : " << endl; 
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    
    // Built max-heap : perform heapify from last 
    // non-leaf node up to root 

    for(int i = arr.size()/2 - 1; i >= 0; i--)
        heapify(arr, i, arr.size()); 
    
     // Print array after max-heapify
    cout << "\nMax-Heap after heapify operation: " << EADDRNOTAVAIL;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}