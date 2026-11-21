// Convert min heap to max heap 

#include<bits/stdc++.h>
using namespace std;


// Recusive approach
// Time Complexity - o(n)
// Space Complexity - o(logn)
void heapify(vector<int> & heap, int n, int i){
    int largest = i; 
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left<n && heap[left]> heap[largest]){
        largest = left; 
    }
    if(right<n && heap[right]> heap[largest]){
        largest = right;  
    }
    if(largest != i){
        swap(heap[i], heap[largest]); 
        heapify(heap, n, largest); 
    }
}
int main(){
    vector<int> Heap = {10, 15, 30, 40, 50, 100, 40};
    int n = Heap.size();

    // Convert to max heap[]
    for(int i = n/2-1; i>= 0; i--){
        heapify(Heap, n, i); 
    }

    cout << "Max Heap array: ";
    for(int i = 0; i < n; i++){
        cout << Heap[i] << " "; 
    }

    return 0;
}